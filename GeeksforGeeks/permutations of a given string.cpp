//backtracking
//there n! permutation each takes n time, so O(n*n!)

#include <bits/stdc++.h>
using namespace std;


void permute(string a, int l, int r){
	if(l==r) cout<<a<<endl; //base case
	else {
		for(int i=l;i<=r;i++){
			swap(a[l], a[i]); //swaping elements
			
			permute(a, l+1, r); //recursion called
			
			swap(a[l], a[i]);  //backtrack
		}
	}
}


int main(){
	string str;
	cin>>str;
	
	int n = str.size();
	
	permute(str, 0, n-1);
	
	return 0;
}
