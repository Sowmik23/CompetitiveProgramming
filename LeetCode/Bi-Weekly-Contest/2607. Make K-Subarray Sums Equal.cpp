// 2607. Make K-Subarray Sums Equal

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        
        int n = arr.size();
        k = gcd(n, k);

        vector<vector<int>> g(k);
        for(int i=0;i<n;i++){
            g[i%k].push_back(arr[i]);
        }

        long long res = 0;
        for(int i=0;i<k;i++){
            sort(g[i].begin(), g[i].end());
            int tmp = g[i][g[i].size()/2];
            for(int j=0;j<g[i].size();j++){
                res+=abs(g[i][j]-tmp);
            }
        }
        return res;
    }
};