class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> jobs;
        
        for(int i=0;i<startTime.size();i++){
            
            //jobs[0] = startTime[i];
            //jobs[1] = endTime[i];
            //jobs[2] = profit[i];
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        
        //sort jobs by start time
        // sort(jobs.begin(), jobs.end(), comp);
        
        ///another way to sort this jobs array
        sort(jobs.begin(), jobs.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] > b[0];
        });
        
        
        int maxProfit = 0;
        map<int, int> dp;
        
        for(auto job: jobs){
            auto it = dp.lower_bound(job[1]);
            
            int prevProfit = (it==dp.end()) ? 0 : it->second;
            
            maxProfit = max(maxProfit, job[2]+prevProfit);
            dp[job[0]] = maxProfit;
        }
        
        
        return maxProfit;
    }

private:
    static bool comp(const vector<int> &a, vector<int> &b){
        return a[0] > b[0];
    }
};
