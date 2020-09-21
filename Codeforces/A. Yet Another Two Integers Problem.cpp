#include <bits/stdc++.h>
using namespace std;

#define ll long long 


int main(){
	
	int n;
	cin>>n;
	
	ll a, b;
	
	while(n--){
		cin>>a>>b;
		
		/*
		int x1 = a/10;
		int y1 = a%10;
		
		int k1,k2;
		if(x1==0 and y1>0) k1 = 1;
		else if(x1>0 and y1>0) {
			k1 = x1+1;
		}
		else k1 = x1;
			
		int x2 = b/10;
		int y2 = b%10;
		if(x2==0 and y2>0) k2 = 1;
		else if(x2>0 and y2>0) {
			k2 = x2+1;
		}
		else {
			k2 = x2;
		}
		
		cout<<k1<<" "<<k2<<endl;
		
		cout<<abs(k1-k2)<<endl;
		*/
		
		ll diff = abs(a-b);
		
		ll d = diff/10;
		ll r = diff%10;
		
		//cout<<d<<" "<<r<<endl;
		
		if(r==0) cout<<d<<endl;
		else cout<<d+1<<endl;
	}
	
	return 0;
}





