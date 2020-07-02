#include <bits/stdc++.h>

using namespace std;

#define ll long long 


int main(){
	
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		ll sum=0;
		for(int i=0;i<n;i++){
			ll x = arr[i];
			while(true){
				sum+=x%10;
				x = x/10;
				if(x==0) break;
			}
		}
		//cout<<sum<<endl;
		if(sum%3==0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
