class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        
        //pre-requisite problem: Subarray sum equal k, L-560
        
        //Time: O(mmn)
        //Space: O(m)
        
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        //calculate the prefix sum of each row
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];

        
        unordered_map<int, int> counter;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                counter ={{0,1}};
                int cur = 0;
                
                for (int k = 0; k < m; k++) {
                    cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        
        return res;
    }
};
