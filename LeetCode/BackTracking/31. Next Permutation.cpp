class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     
        int pivot, index=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]) {
                pivot = nums[i];
                index = i;
                break;
            }
        }
        
        if(index==-1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int tmp;
        for(int i=nums.size()-1;i>index;i--){
            if(nums[i]>pivot){
                tmp = i;
                break;
            }
        }
        swap(nums[index], nums[tmp]);
        reverse(nums.begin()+index+1, nums.end());
      
    }
};
