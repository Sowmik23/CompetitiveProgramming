//time complexity: O(n*r)
//this codes takes long time for large number of n
//Dynamic version. for accepted code see lucas algorithm 

#include <bits/stdc++.h>
using namespace std;


//Combination ---> pascal triangle

#define ll long long 

ll nCrModm(ll n, ll r, ll mod){
	if(r>n-r){
		r = n-r;
	}
	
	//this array will store the last row of pascal
	//triangle at the end. and the last entry of last row is nCr
	
	ll arr[r+1];
	memset(arr, 0, sizeof(arr));
	
	arr[0] = 1; //top row of pascal triangle
	
	//triangle from top to bottom
	for(ll i =0;i<=n;i++){
		//fill entries using previous row
		for(ll j=min(i, r); j>0;j--){
			arr[j] = (arr[j] + arr[j-1])%mod;
		}
	}
	return arr[r];
}


int main(){
	
	int t;
	cin>>t;
	while(t--){
		ll n, r, m;
		cin>>n>>r>>m;
		
		cout<<nCrModm(n, r, m)<<endl;
	}
	
	return 0;
}
