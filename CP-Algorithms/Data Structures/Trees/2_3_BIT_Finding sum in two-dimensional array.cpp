#include <bits/stdc++.h>
using namespace std;


struct FenwickTree2D {
	vector<vector<int>> bit;
	int n, m;
	
	FenwickTree2D(int n, int m){
		this->n = n;
		this->m = m;
		
		vector<vector<int>> bit(n, vector<int> (m, 0));
	}
	
	
	FenwickTree2D(vector<vector<int>> a) {
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				add(i, j, a[i][j]);
			}
		}
	}
	
	
	int getSum(int x, int y){
		int res = 0;
		cout<<"where is the problem"<<endl;
		for(int i=x;i>=0;i = (i&(i+1)) -1){
			for(int j=y;j>=0;j = (j&(j+1)) - 1) {
				cout<<bit[i][j]<<" ";
				res += bit[i][j];
			}
		}
		return res;
	}
	
	void add(int x, int y, int val){
		for(int i=x;i<n;i=i|(i+1)){
			for(int j=y;j<m;j=j|(j+1)){
				bit[i][j] += val;
			}
		}
	}
};

int main(){
	
	int n, m, x;
	vector<vector<int>> v;
	
	scanf("%d%d", &n, &m);
	
	for(int i=0;i<n;i++){
		vector<int> row;
		for(int j=0;j<m;j++){
			scanf("%d", &x);
			row.push_back(x);
		}
		v.push_back(row);
	}
	
	cout<<"ok1"<<endl;
	FenwickTree2D BIT = FenwickTree2D(n, m);
	cout<<"ok2"<<endl;
	FenwickTree2D fn = FenwickTree2D(v);
	cout<<"ok3"<<endl;
	int d = fn.getSum(1, 1);
	printf("%d\n", d);
	
	
	return 0;
}
/*

4 4
1 2 3 4 
5 3 8 1 
4 6 7 5 
2 4 8 9 

*/
