class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        
        ///approach-01: Time: O(n), Memory: O(n)
        /*
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            res.insert(res.begin()+index[i], nums[i]);
        }
        
        return res;
        */
        ///approach-02: Time:O(n), Memory: O(1)
        
        for(int i=0;i<nums.size();i++){

            if(i!=index[i]){
                int tmp = nums[i];
                nums.erase(nums.begin() + i);
                nums.insert(nums.begin()+ index[i], tmp);           
            }
        }
        return nums;
    }
};
