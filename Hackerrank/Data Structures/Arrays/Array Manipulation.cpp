#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
	ll n, m, a, b, k;
	
	cin>>n>>m;
	
	ll *arr = new ll [n+1]();
	for(ll i=1;i<=n;i++) arr[i] = 0;
	
	while(m--){
		cin>>a>>b>>k;
		arr[a] +=k;
		if(b+1<=n) arr[b+1]-=k;
		///cout<<endl;
		///for(int i=1;i<=n;i++)cout<<arr[i]<< " ";
		///cout<<endl;
	}
	
	ll x=0, ans=0;
	for(ll i=1;i<=n;i++){
		x+=arr[i];
		if(ans<x) ans = x;
	}
	cout<<ans<<endl;
	delete [] arr;
	
	return 0;
}
