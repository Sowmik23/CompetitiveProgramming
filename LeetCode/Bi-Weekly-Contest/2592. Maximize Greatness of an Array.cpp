// 2592. Maximize Greatness of an Array
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
     
        sort(nums.begin(), nums.end());
        int cnt = 0;

        int i = 0;
        for(auto& n: nums){
            if(n>nums[i]){
                i++;
                cnt++;
            }
        }
        return cnt;
    }
};