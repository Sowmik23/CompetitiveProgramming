class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        //Log(n) solution
        
        int left = 0, right = nums.size()-1;
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            //if mid and target are on the same side
            if( (nums[mid]-nums[nums.size()-1])*(target-nums[nums.size()-1])>0){
                if(target>nums[mid]){
                    left = mid+1;
                }    
                else {
                    right = mid;
                }
            }
            else if(target>nums[nums.size()-1]){
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        //cout<<left<<endl;
        if(nums[left]==target) return left;
        return -1;
    }
};
