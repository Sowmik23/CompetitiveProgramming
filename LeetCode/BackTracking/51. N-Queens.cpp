#include <bits/stdc++.h>
using namespace std;

///Time: O(N!)
///Memory: O(N)

///Given an integer n, return all distinct solutions to the n-queens puzzle.


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
     
        vector<string> grid;
        string str = "";
        for(int i=0;i<n;i++){
			str+='.';
		}
		for(int i=0;i<n;i++) grid.push_back(str);
		
		vector<vector<string>> ans;
		
		ans = backtrack(grid, 0, n);
		
		return ans;
    }
    
private:
	vector<vector<string>> ans;
	vector<vector<string>> backtrack(vector<string> grid, int col, int n){
		if(col==n){
			ans.push_back(grid);
			return ans;
		}
		
		for(int i=0;i<n;i++){
			if(isPossible(grid, i, col, n)){
				grid[i][col] = 'Q';
				backtrack(grid, col + 1, n);
				grid[i][col] = '.';
			}
		}
		return ans;
	}
	
	bool isPossible(vector<string> grid, int row, int col, int n){
		
		///checking columns
		for(int i=0;i<col;i++){
			if(grid[row][i] == 'Q') return false;
		}
		
		///checking upper left diagonal: as we fill column wise
		for(int i=row-1, j = col-1;i>=0 and j>=0;i--, j--){
			if(grid[i][j]=='Q') return false;
		}
		
		///checking lower left diagonal
		for(int i= row+1, j = col-1;i<n and j>=0; i++, j--){
			if(grid[i][j]=='Q') return false;
		}
		return true;
	}
};


int main(){
	
	Solution s;
	
	int n;
	cin>>n;
	vector<vector<string>> res;
	
	res = s.solveNQueens(n);
	
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<endl;
		}
		cout<<"Another pattern"<<endl;
	}
	
	cout<<"finished"<<endl;
	
	return 0;
}
