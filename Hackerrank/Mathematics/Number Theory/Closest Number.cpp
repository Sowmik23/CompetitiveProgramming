#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main(){
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int a, b, x;
		cin>>a>>b>>x;
		
		unsigned long long k = pow(a, b);
		ll mod = k%x;
		if(mod>x/2) cout<<k+x-mod<<endl;
		else cout<<k-mod<<endl;
		
	}
	
	
	return 0;
}
