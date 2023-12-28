// 646. Maximum Length of Pair Chain
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        //greedy + sorting
        // Time: O(nlogn)
        /*
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b){
            return a[1]<b[1];
        });

        // for(auto& p: pairs) cout<<p[0]<<" "<<p[1]<<endl;

        int cnt = 1;
        int a = pairs[0][0];
        int b = pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(b<pairs[i][0]){
                cnt++;
                a = pairs[i][0];
                b = pairs[i][1];
            }
        }

        return cnt;
        */


        //Recursive Dynamic Programming
        // Time: O(n^2)
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> memo(n);

        int res = 0;
        for(int i=0;i<n;i++){
            res = max(res, longestPairChain(i, pairs, n, memo));
        }

        return res;
    }
private:    
    int longestPairChain(int i, vector<vector<int>> &pairs, int n, vector<int> &memo){
        if(memo[i]) return memo[i];
        memo[i] = 1;
        for(int j=i+1;j<n;j++){
            if(pairs[i][1]<pairs[j][0]){
                memo[i] = max(memo[i], 1+longestPairChain(j, pairs, n, memo));
            }
        }
        return memo[i];
    }
};