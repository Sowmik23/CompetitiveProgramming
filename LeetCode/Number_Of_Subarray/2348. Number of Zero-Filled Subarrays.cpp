// 2348. Number of Zero-Filled Subarrays


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long res = 0;
        long long cnt = 0;

        for(auto& n: nums) {
            if(n==0) {
                cnt++;
            }
            else cnt = 0;
            res +=cnt;
        }
        return res;
    }
};


