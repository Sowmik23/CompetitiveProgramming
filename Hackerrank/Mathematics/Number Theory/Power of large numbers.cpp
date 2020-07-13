#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long 

ull m = 10e9 + 7;

ull power(ull a, ull b){
	ull ans = 1;
	a = a%m;
	while(b){
		if(b&1) ans = (ans*a)%m;
		a = (a*a)%m;
		b = b>>1;
	}
	return (ans%m);
}


int main(){
	int t;
	cin>>t;
	while(t--){
		ull a, b;
		cin>>a>>b;
		
		cout<<power(a,b)<<endl;
	}
	
	
	return 0;
}
