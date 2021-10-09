class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs_visit(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
private:
    bool dfs_visit(int i, int j, vector<vector<char>> &board, string &word, int index){
        
        if(index==word.size()) return true;
        
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size()) return false;
        
        if(board[i][j]!=word[index]) return false;
        
        board[i][j] = '*';
        
        bool res = dfs_visit(i+1, j, board, word, index+1) or
                dfs_visit(i-1, j, board, word, index+1) or
                dfs_visit(i, j+1, board, word, index+1) or
                dfs_visit(i, j-1, board, word, index+1);
        
        board[i][j] = word[index];

        return res;
    }
};
