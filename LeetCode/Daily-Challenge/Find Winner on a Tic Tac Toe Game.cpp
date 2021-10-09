class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        vector<vector<char>> grid(3, vector<char> (3, '.'));
        
        for(int i=0;i<moves.size();i++){
            
            if(i%2==0) grid[moves[i][0]][moves[i][1]] = 'X';
            else grid[moves[i][0]][moves[i][1]] = 'O';
        }
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
        bool flag = false;
        if(moves.size()>=5){
            flag = true;
            //check rows
            int a = 0, b =0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(grid[i][j]=='X') a++;
                    else if(grid[i][j]=='O') b++;
                }  
                if(a==3) return "A";
                else a = 0;
                if(b==3) return "B";
                else b = 0;
            }
            
            
            //check col
            a = 0, b = 0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(grid[j][i]=='X') a++;
                    else if(grid[j][i]=='O') b++;
                }
                if(a==3) return "A";
                else a = 0;
                if(b==3) return "B";
                else b = 0;
            }
            
            //check diagonals
            a = 0, b = 0 ;
            for(int i=0;i<3;i++){
                if(grid[i][i]=='X') a++;
                else if(grid[i][i]=='O') b++;
            }
            // cout<<"Dia1: "<<a<<" "<<b<<endl;
            if(a==3) return "A";
            if(b==3) return "B";
            
            //check another diagonal
            a = 0, b = 0;
            int j =0;
            for(int i=2;i>=0;i--){
                if(grid[i][j]=='X') a++;
                else if(grid[i][j]=='O') b++;
                j++;
            }
            // cout<<"Dia2: "<<a<<" "<<b<<endl;
            if(a==3) return "A";
            if(b==3) return "B";
        }
        if(moves.size()!=9){
            return "Pending";
        }
        if(flag==true and moves.size()==9) return "Draw";
        return "";
    }
};

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        ///Time: O(m) m = moves.size(), Space: O(n) n = 3;
        
        vector<int>  rows(3);
        vector<int> cols(3);
        int dia1 = 0;
        int dia2 = 0;
        int player = 1;
        
        for(int i=0;i<moves.size();i++){
            
            int r = moves[i][0];
            int c = moves[i][1];
            
            rows[r] += player;
            cols[c] += player;
            
            if(r==c){
                dia1+=player;
            }
            if(r+c==3-1) {
                dia2+=player;
            }
            
            if(abs(rows[r])==3 or abs(cols[c])==3 or abs(dia1)==3 or abs(dia2)==3) {
                if(player==1) return "A";
                else return "B";
            }
            
            player *=-1;
        }
        
        if(moves.size()!=9) return "Pending";
        else return "Draw";
    }
};
