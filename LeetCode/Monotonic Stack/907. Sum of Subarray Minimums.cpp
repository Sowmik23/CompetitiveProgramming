class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {


       //brute force: n^2(TLE)
        /*
        const int mod = 1e9+7;
        int n = arr.size();
        int res = 0;
        for(int i=0;i<n;i++){
            int mn = arr[i];
            for(int j=i;j<n;j++){
                mn = min(mn,  arr[j]);
                res+=mn;
                res = res%mod;
            }
        }
        return res%mod;
        */

        //using monotonic stack:  Time:O(n), Space: O(n);
        const int mod = 1e9+7;
        stack<int> stk;
        vector<int> dp(arr.size());


        for(int i=0;i<arr.size();i++){
            while(!stk.empty() and arr[stk.top()]>=arr[i]) stk.pop();

            if(!stk.empty()){
                int prevSmaller = stk.top();
                dp[i] = dp[prevSmaller] + (i-prevSmaller)*arr[i];
            }
            else {
                dp[i] = (i+1)*arr[i];
            }

            stk.push(i);
        }
        long res = 0;
        for(auto& d: dp){
            res+=d;
            res%=mod;
        }

        return res%mod;
    }
};
