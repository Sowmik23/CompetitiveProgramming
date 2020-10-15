#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


int main(){
	
	ll n;
	cin>>n;
	ll arr[n+5];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int k;
	cin>>k;
	for(int i=0;i<n;i++){
		if(arr[i]==k) cout<<i<<endl;
	}
	
	
	return 0;
}
