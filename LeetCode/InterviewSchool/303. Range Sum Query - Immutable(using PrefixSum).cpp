class NumArray {
public:
    vector<int> nums;
    vector<int> prefixSums;
    
    NumArray(vector<int>& nums) {
        this->nums = nums;
        
        prefixSums = vector<int> (nums.size());
        prefixSums[0] = nums[0];
        
        for(int i=1;i<nums.size();i++){
            prefixSums[i] = nums[i];
            prefixSums[i] +=prefixSums[i-1];            
        }
    }
    
    int sumRange(int left, int right) {
        //cout<<prefixSums[right]<<" "<<prefixSums[left]<<endl;
        
        return prefixSums[right]-prefixSums[left]+nums[left];    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
