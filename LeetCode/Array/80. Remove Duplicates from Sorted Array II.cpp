class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j=0, cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[j] and cnt<2){
                j++;
                nums[j] = nums[i];
                cnt++;
            }
            else if(nums[i]!=nums[j]){
                j++;
                nums[j] = nums[i];
                cnt=1;
            }
        }
        return j+1;
    }
};
