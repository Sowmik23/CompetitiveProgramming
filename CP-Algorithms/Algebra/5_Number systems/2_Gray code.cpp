#include <bits/stdc++.h>
using namespace std;

/*
 * Gray code is a binary numeral system where two successive values
 * differ in only one bit.
 * This code was invented by Frank Gray in 1953.
*/


/// finding gray code
int g(int n){
	return n^(n>>1);
}


/// finding inverse gray code;
int rev_g(int g){
	int n = 0;
	for(; g; g>>=1){
		n^=g;
	}
	return n;
}


int main(){
	
	int n;
	scanf("%d", &n);
	
	int d = g(n);
	cout<<d<<endl;
	
	int k = rev_g(d);
	cout<<k<<endl;
	
	
	return 0;
}
