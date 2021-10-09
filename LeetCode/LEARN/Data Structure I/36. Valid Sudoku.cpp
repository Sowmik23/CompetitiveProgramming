class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<string, int> mp;
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                
                string r = "row"+to_string(i)+to_string(board[i][j]);
                string c = "col"+to_string(j)+to_string(board[i][j]);
                string box = "box"+to_string((i/3)*3+(j/3))+to_string(board[i][j]);
                
                if(mp.count(r) or mp.count(c) or mp.count(box)) return false;
                mp[r]++;
                mp[c]++;
                mp[box]++;
            }
        }
        
        return true;
    }
};
