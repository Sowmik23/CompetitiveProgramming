#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int res = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    res++;
                    dfs_visit(grid, i, j);
                }
            }
        }
        
        return res;
    }
    
private:
    bool isValid(vector<vector<char>> &grid, int x, int y){
        if((x>=0 and y>=0) and (x<grid.size() and y<grid[0].size())) return true;
        return false;
    }
    void dfs_visit(vector<vector<char>> &grid, int x, int y){
        queue<pair<int, int>> q;
        q.push({x, y});
        
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            pair<int, int> pa;
            
            pa = q.front();
            q.pop();
            int a = pa.first;
            int b = pa.second;
            
            for(int i=0;i<4;i++){  
                int posX = a + row[i];
                int posY = b + col[i];

                if(isValid(grid, posX, posY) and grid[posX][posY]=='1'){
                    grid[posX][posY] = '0';
                    q.push({posX, posY});
                }
            }
        }
        
    }
};

int main(){
	
	Solution s;
	
	vector<vector<char>> grid = {
		  {"1","1","1","1","0"},
		  {"1","1","0","1","0"},
		  {"1","1","0","0","0"},
		  {"0","0","0","0","0"}
		  };
	
	int ans = s.numIslands(grid);
	
	cout<<ans<<endl;

	return 0;
}
