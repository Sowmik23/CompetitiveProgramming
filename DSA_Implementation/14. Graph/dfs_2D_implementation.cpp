#include <bits/stdc++.h>
using namespace std;


///Time: O(N*M)
///Memory:O(N*M);


#define ROW 3  //this is same as input r 
#define COL 3 //this is same as input c

int row[] = {0, 1, 0, -1};
int col[] = {-1, 0, 1, 0};

bool isValid(int x, int y, vector<vector<bool>> &visited){
	if(x<0 or y<0 or x>=ROW or y>=COL) return false;
	if(visited[x][y]==true) return false;
	return true;
}


void dfs_grid(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y){
	stack<pair<int, int>> st;
	st.push(make_pair(x, y));
	
	while(!st.empty()){
		pair<int, int> f = st.top();
		st.pop();
		
		int x = f.first;
		int y = f.second;
		
		if(!isValid(x, y, visited)) continue;
		
		visited[x][y] = true;
		
		cout<<grid[x][y]<<" ";
		
		for(int i=0;i<4;i++){
			int posX = x + row[i];
			int posY = y + col[i];
			st.push(make_pair(posX, posY));
		}
	}
}



int main(){
	
	int r, c, x;
	cin>>r>>c;
	
	vector<vector<int>> grid;
	vector<vector<bool>> visited(r, vector<bool> (c, false));
	
	for(int i=0;i<r;i++){
		vector<int> tmp;
		for(int j=0;j<c;j++){
			cin>>x;
			tmp.push_back(x);
		}
		grid.push_back(tmp);
	}
	
	dfs_grid(grid, visited, 0, 0);
	
	
	return 0;
}
/*
Input:
3 3
-1 2 3
0 9 8
1 0 1
Output: -1 2 3 8 1 0 9 0 1
*/
