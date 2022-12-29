class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        bool res = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    res = dfs(board, word, visited, i, j, 0);
                    if(res) return res;
                }
            }
        }
        return res;
    }
private:
    vector<int> directions = {1, 0,  -1, 0, 1};
    bool dfs(vector<vector<char>> &board, string word, vector<vector<bool>> &visited, int i, int j, int l){

         if(l==word.size()) return true;
         if(!(i>=0 and i<board.size() and j>=0 and  j<board[0].size())) return false;
        if(board[i][j]!=word[l]) return false;
         if(visited[i][j]) return false;
         visited[i][j]  = true;

         bool res = false;
         for(int k=0;k<4;k++){
             int m = i+directions[k];
             int n = j+directions[k+1];

             res =  res or dfs(board, word, visited, m, n, l+1);
         }
         visited[i][j]=false;

         return res;
     }
};

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
