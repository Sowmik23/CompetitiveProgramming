// 1425. Constrained Subsequence Sum


class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        //Approach-01: Using priority queue
        //Time: O(nlogn)
        /*
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});

        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            while(i-pq.top().second>k) pq.pop();

            int curr = max(0, pq.top().first) + nums[i];
            res = max(res, curr);
            pq.push({curr, i});
        }
        return res;
        */

        //Approach-02: Using tree map like data structure
        //Time: O(nlogn)
        /*
        map<int, int> window;
        window[0] = 0;
        vector<int> dp(nums.size());

        for(int i=0;i<nums.size();i++){
            dp[i] = nums[i] + window.rbegin()->first;
            window[dp[i]]++;

            if(i>=k){
                window[dp[i-k]]--;
                if(window[dp[i-k]]==0){
                    window.erase(dp[i-k]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
        */

        //Approach-03: Monotonic Deque :: Similar to sliding window maximum
        //Time: O(n)
        deque<int> dq;
        vector<int> dp(nums.size());

        for(int i=0;i<nums.size();i++){
            if(!dq.empty() and i-dq.front()>k){
                dq.pop_front();
            }

            dp[i] = (!dq.empty() ? dp[dq.front()] : 0) + nums[i];
            while(!dq.empty() and dp[dq.back()]<dp[i]){
                dq.pop_back();
            }

            if(dp[i]>0){
                dq.push_back(i);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};