#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


int main(){
	
	ll n, w, h;
	int cnt=0;
	cin>>n;
	while(n--){
		cin>>w>>h;
		
		double d;
		if(w>h) d = (double)w/h;
		else d = (double)h/w;
		
		if(d<=1.7 and d>=1.6) cnt++;
		
	}
	cout<<cnt;
	
	
	return 0;
}
