class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        
        int row = box.size();
        int column = box[0].size();
        
        for(int i=0;i<row;i++){
            
            int obstacle = column-1, stone=0;
            for(int j = column-1; j>=0;j--){
                if(box[i][j]=='*'){
                    obstacle = j-1;
                    stone = 0;
                }
                else if(box[i][j]=='#'){
                    box[i][j] = '.';
                    int newJ = obstacle-stone;
                    box[i][newJ] = '#';
                    stone++;
                }  
            }
        }
        
        // for(int i=0;i<box.size();i++){
        //     for(int j=0;j<box[i].size();j++){
        //         cout<<box[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        
        // rotating this 2d vector in 90 degree clockwise
        vector<vector<char>> res;
        
        
        for(int i=0;i<column;i++){
            
            vector<char> tmp;
            for(int j=row-1;j>=0;j--){
                tmp.push_back(box[j][i]);
            }       
            res.push_back(tmp);
        }
        
        return res;
    }
};
