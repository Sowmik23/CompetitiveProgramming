#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
	vector<int> bit; 	///binary indexed tree -> bit
	int n;
	const int INF = 1e9; 
	
	FenwickTree(int n){
		this->n = n;
		bit.assign(n, INF);
	}
	
	FenwickTree(vector<int> a): FenwickTree(a.size()) {
		for(size_t i=0;i<a.size();i++){
			update(i, a[i]);
		}
	}
	
	int getMin(int r){
		int res = INF;
		while(r>=0){
			res = min(res, bit[r]);
			r = (r&(r+1)) - 1;
		}
		
		return res;
	}
	
	void update(int idx, int val){
		while(idx<n){
			bit[idx] = min(bit[idx], val);
			idx = idx | (idx+1);
		}
	}
};


int main(){
	
	int n, x;
	vector<int> v;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &x);
		v.push_back(x);
	}
	
	FenwickTree fn = FenwickTree(n);
	FenwickTree BIT = FenwickTree(v);
	
	int d = BIT.getMin(5);
	printf("Minimum of 0 to 5 is: %d\n", d);
	
	
	
	return 0;
}
