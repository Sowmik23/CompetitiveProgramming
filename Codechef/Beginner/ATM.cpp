#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b, a%b);
}



int main(){
	
	int x;
	double y;
	cin>>x>>y;
	
	if(x%5==0 and x+0.5<=y){
		y = y-x;
		y -=0.50;
	}
	cout<<setprecision(2)<<fixed<<y<<endl;
	
	
	return 0;
}
