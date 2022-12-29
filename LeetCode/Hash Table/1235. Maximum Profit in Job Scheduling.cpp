class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        map<int, int> dp;
        vector<vector<int>> jobs;

        for(int i=0;i<startTime.size();i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end(), [](const auto& a, const auto& b){
            return a[0]>b[0];
        });


        int maxProfit = 0;
        for(auto& job: jobs){
            auto it = dp.lower_bound(job[1]);
            int pre = (it==dp.end() ? 0 : it->second);
            maxProfit = max(maxProfit, pre+job[2]);
            dp[job[0]] = maxProfit;
        }

        return maxProfit;
    }
};
