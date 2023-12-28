class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        long sum = 0;
        for(auto& num: nums) sum+=num;

        long x = 0;
        long ans = INT_MAX;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            x+=nums[i];
            long a = x/(i+1);
            long b = 0;
            if(i!=nums.size()-1) b = (sum-x)/(nums.size()-i-1);
            long c = abs(a-b);
            if(c<ans) {
                ans = c;
                res = i;
            }
        }
        return res;
    }
};
