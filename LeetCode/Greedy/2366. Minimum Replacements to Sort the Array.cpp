// 2366. Minimum Replacements to Sort the Array
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        

        //Time: O(n)
        long long cnt = 0;
        int n = nums.size();
        
        for(int i=n-2;i>=0;i--){

            if(nums[i]<=nums[i+1]){
                continue;
            }
            else {
                long total_replacement = (long)(nums[i]+nums[i+1]-1)/(nums[i+1]);
                cnt+=total_replacement-1;
                nums[i] = nums[i]/total_replacement;
            }
        }
        return cnt;
    }
};