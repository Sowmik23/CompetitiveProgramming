class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {

        long mod = 1e9+7;
        //DP on tree
        unordered_map<int, int> mp;
        vector<long> dp(arr.size(), 1);
        sort(arr.begin(), arr.end());

        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = i;
            for(int j=i-1;j>=0;j--){
                if(arr[i]%arr[j]==0){ //to check whether arr[j] is a factor of arr[i] or not
                    int tmp = arr[i]/arr[j];
                    if(mp.count(tmp)){
                        dp[i] +=(dp[j]*dp[mp[tmp]])%mod; //check the presence of the required no in map, If it is in the map then increase dp[i] by the product of the dp[j] and dp[mp[temp]] taking the modulus
                    }
                }
            }
        }

        long long sum = 0;
        sum = accumulate(dp.begin(), dp.end(), 0LL);

        return sum%mod;
    }
};
