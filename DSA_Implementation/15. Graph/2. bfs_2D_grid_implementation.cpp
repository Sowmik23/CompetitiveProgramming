#include <bits/stdc++.h>
using namespace std;

///Time : O(N*M)
///Memory:O(N*M)


#define ROW 4
#define COL 4

///direction vectors
int row[] = {-1, 0, 1, 0};
int col[] = {0, 1, 0, -1};

bool isValid(int r, int c){
	if(r<0 or c<0 or r>=ROW or c>=COL) return false;
	
	return true;
}


void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int r, int c){
	queue<pair<int, int>> q;
	
	q.push(make_pair(r, c));
	visited[r][c] = true;
	
	while(!q.empty()){
		pair<int,int> f = q.front();
		q.pop();
		int x = f.first;
		int y = f.second;
		
		//print the value
		cout<<grid[x][y]<<" ";
		
		///now go to the adjacent cells
		for(int i=0;i<4;i++){
			
			int adjX = x + row[i];
			int adjY = y + col[i];
			
			if(isValid(adjX, adjY)==true){
				if(visited[adjX][adjY]==false){
					q.push(make_pair(adjX, adjY));
					visited[adjX][adjY] = true;
				}
			}
		}
	}
}


int main(){
	
	int r, c, val;
	cin>>r>>c;
	
	vector<vector<int>> grid;
	vector<vector<bool>> visited(r, vector<bool> (c, false));
	
	for(int i=0;i<r;i++){
		vector<int> tmp;
		for(int j=0;j<c;j++){
			cin>>val;
			tmp.push_back(val);
		}
		grid.push_back(tmp);
	}
	
	/*for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	bfs(grid, visited, 0, 0);
	
	
	return 0;
}
/*
Input:
4 4
1 2 3 4 
5 6 7 8
9 10 11 12
13 14 15 16

Output: 1 2 5 3 6 9 4 7 10 13 8 11 14 12 15 16
*/
