#include <bits/stdc++.h>
using namespace std;

/// Complexity: O(log n)
/// 0 based indexing

struct FenwickTree {
	vector<int> bit; ///binary indexed tree -> bit
	int n;
	
	FenwickTree(int n){
		this->n = n;
		bit.assign(n, 0);
	}
	
	FenwickTree(vector<int> a): FenwickTree(a.size()) {
		for(size_t i=0; i<a.size();i++){
			add(i, a[i]);
		}
	}
	
	int sum(int r){
		int res = 0;
		while(r>=0){
			res += bit[r];
			r = (r&(r+1))-1;  //same as r = (r&(r+1)) - 1;
		}
		
		return res;
	}
	
	int sum(int l, int r){
		return sum(r) - sum(l-1);
	}
	
	void add(int idx, int val){
		while(idx<n){
			bit[idx] += val;
			idx = (idx | (idx + 1));
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
	
	FenwickTree BIT = FenwickTree(n);
	FenwickTree bit = FenwickTree(v);
	
	int d = bit.sum(4);
	printf("Sum of index 0 to index 4 is: %d\n", d);

	int k = bit.sum(2, 5);
	printf("Sum of index 2 to 5 is: %d\n", k);	
	
	
		
	return 0;
}
