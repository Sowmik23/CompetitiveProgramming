class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       
        int row[] = { 1, 0, -1, 0};
        int col[] = { 0, -1, 0, 1};
        
        int color = image[sr][sc];
        
        vector<vector<bool>> visited(image.size(), vector<bool> (image[0].size(), false));
        
        stack<pair<int, int>> stk;
        stk.push(make_pair(sr, sc));
        
        while(!stk.empty()){
            pair<int, int> top = stk.top();
            stk.pop();
            
            int x = top.first;
            int y = top.second;
            
            if(!isValid(x, y, visited) or image[x][y]!=color) continue;
            
            visited[x][y] = true;
            image[x][y] = newColor;
            cout<<x<<" "<<y<<endl;
            
            for(int i=0;i<4;i++){
                int posX = x + row[i];
                int posY = y + col[i];
                
                // if(image[posX][posY]==color){
                  //  cout<<posX<<" "<<posY<<endl;
                    stk.push(make_pair(posX, posY));
                // }
            }
        }
                
        return image;
    }
    
private:
    bool isValid(int x, int y, vector<vector<bool>> &visited){
        if(x<0 or y<0 or x>=visited.size() or y>=visited[0].size()) return false;
        if(visited[x][y]==true) return false;
        return true;
    }
    
};
