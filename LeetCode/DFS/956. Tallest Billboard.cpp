// 956. Tallest Billboard
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        
        //interesting problem: but very hard

        //DFS + Memoization
        //Time: 3^n
        // return dfs(rods, 0, 0, 0);

        int m_sum = accumulate(rods.begin(), rods.end(), 0)/2;
        vector<vector<int>> memo(rods.size(), vector<int> (m_sum+1, -2));

        return max(0, dfsWithMemo(rods, 0, 0, 0, m_sum, memo));
    }
private:
    int dfs(vector<int> &rods, int i, int s1, int s2){
        if(i>=rods.size()) return s1==s2 ? s1 : 0;

        return max( {dfs(rods, i+1, s1, s2), dfs(rods, i+1,s1+rods[i], s2), dfs(rods, i+1, s1, s2+rods[i])});
    }

    int dfsWithMemo(vector<int> &rods, int i, int s1, int s2, int m_sum, vector<vector<int>> &memo){
        if(s1>m_sum or s2>m_sum) return -1;
        if(i>=rods.size()) return s1==s2 ? s1 : -1;

        if(memo[i][abs(s1-s2)]==-2){
            memo[i][abs(s1-s2)] = max(-1, max({
                dfsWithMemo(rods, i+1, s1, s2, m_sum, memo),
            dfsWithMemo(rods, i+1, s1+rods[i], s2, m_sum, memo), 
            dfsWithMemo(rods, i+1, s1, s2+rods[i], m_sum, memo)}) - max(s1, s2));
        }
        return memo[i][abs(s1-s2)] + (memo[i][abs(s1-s2)] == -1 ? 0 : max(s1, s2));
    }

};
