// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        
        //I thought it's a math problem
        //But it's a bad dp

        //TLE
        // return recursive(n, m, k, 0, 0, 0);

        //recursion with memoization
        // Time: O(n*m*k*m)
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        return recursionWithMemo(n, m, k, 0, 0, 0, memo);
    }
private:
    const int mod = 1e9+7;
    int recursive(int n, int m, int k, int i, int currMx, int currCost){
        if(i==n){
            if(currCost==k) return 1;
            return 0;
        }

        int cnt = 0;
        
        for(int val = 1;val<=m;val++){
            int newCost = currCost, newMx = currMx;
            if(val>currMx){
                newMx = val;
                newCost++;
            }
            if(newCost>k) break;
            cnt+=recursive(n, m, k, i+1, newMx, newCost);
            cnt%=mod;
        }
        return cnt;
    }   

    int recursionWithMemo(int n, int m, int k, int i, int currMx, int currCost, vector<vector<vector<int>>> &memo){
        if(i==n){
            if(currCost==k) return 1;
            return 0;
        }

        if(memo[i][currMx][currCost]!=-1) return memo[i][currMx][currCost];

        int cnt = 0;
        for(int val=1;val<=m;val++){
            int newMx = currMx;
            int newCost = currCost;
            if(val>currMx){
                newMx = val;
                newCost++;
            }
            if(newCost>k) break;
            cnt+=recursionWithMemo(n, m, k, i+1, newMx, newCost, memo);
            cnt%=mod;
        }
        return memo[i][currMx][currCost] = cnt;
    }
};