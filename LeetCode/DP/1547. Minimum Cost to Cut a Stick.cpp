// 1547. Minimum Cost to Cut a Stick
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        int m = cuts.size();
        vector<int> newCuts(m+2);

        for(int i=0;i<m;i++){
            newCuts[i+1] = cuts[i];
        }
        newCuts[m+1] = n;
        sort(newCuts.begin(), newCuts.end());

        vector<vector<int>> memo(m+2, vector<int> (m+2, -1));

        return cost(0, newCuts.size()-1, newCuts, memo);
    }
private:
    int cost(int left, int right, vector<int> &newCuts, vector<vector<int>> &memo){
        if(memo[left][right]!=-1) return memo[left][right];
        if(right-left<=1) return 0;

        int res = INT_MAX;
        for(int i=left+1;i<right;i++){
            int cst = cost(left, i, newCuts, memo)+cost(i, right, newCuts, memo)+newCuts[right]-newCuts[left];
            res = min(res, cst);
        }
        return memo[left][right] = res;
    }
};