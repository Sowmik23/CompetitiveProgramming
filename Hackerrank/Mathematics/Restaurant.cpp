#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	int x = a%b;
	if(x==0) return b;
	a = b;
	b = x;
	return gcd(a,b);
}

int main(){
	
	int t, l, b, res;
	cin>>t;
	while(t--){
		cin>>l>>b;
		if(l==b) res = 1;
		else {
			int k = gcd(l,b);
			res = (l*b)/(k*k);
		}
		cout<<res<<endl;
		
	}
	
	return 0;
}
