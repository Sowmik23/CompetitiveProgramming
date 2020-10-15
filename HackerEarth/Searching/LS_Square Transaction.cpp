#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

int main(){
	int n, q;
	cin>>n;
	
	ll arr[n+4];
	ll query[9990009];
	ll sum=0;
	
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		for(int j=sum+1;j<=sum+arr[i];j++) {
			query[j] = i+1;
		}
		sum+=arr[i];
	}
	//for(int i=0;i<50;i++) cout<<query[i]<<" ";
	
	ll value;
	cin>>q;
	while(q--){
		cin>>value;
		if(query[value]!=0) cout<<query[value]<<endl;
		else cout<<"-1"<<endl;
	}
	
	
	return 0;
}
