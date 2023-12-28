// 1751. Maximum Number of Events That Can Be Attended II
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        

        //sorting with dp
        //Time: O(n^2)
        /*
        int n = events.size();

        //sort with increasing with start time
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return a[0]<b[0];
        });
        return dfs(0, 0, -1, events, k);
        */

        //recursion with memoization
        int n = events.size();

        //sort with increasing with start time
        sort(events.begin(), events.end(), [](auto& a, auto& b){
            return a[0]<b[0];
        });
        vector<vector<int>> memo(k+1, vector<int> (n, -1));
        return recursionWithMemo(0, 0, -1, events, k, memo);
    }
private:
    int dfs(int idx, int cnt, int prevEndTime, vector<vector<int>> &events, int k){

        if(idx==events.size() or cnt==k) return 0;
        if(prevEndTime>=events[idx][0]) return dfs(idx+1, cnt, prevEndTime, events, k);

        return max(dfs(idx+1, cnt, prevEndTime, events, k), 
                    dfs(idx+1, cnt+1, events[idx][1], events, k)+events[idx][2]);
    }

    int recursionWithMemo(int idx, int cnt, int prevEndTime, vector<vector<int>> &events, int k, vector<vector<int>> &memo){

        if(idx==events.size() or cnt==k) return 0;
        if(prevEndTime>=events[idx][0]) return recursionWithMemo(idx+1, cnt, prevEndTime, events, k, memo);

        if(memo[cnt][idx]!=-1) return memo[cnt][idx];

        return memo[cnt][idx] = max(recursionWithMemo(idx+1, cnt, prevEndTime, events, k, memo), 
                    recursionWithMemo(idx+1, cnt+1, events[idx][1], events, k, memo)+events[idx][2]);
    }
};