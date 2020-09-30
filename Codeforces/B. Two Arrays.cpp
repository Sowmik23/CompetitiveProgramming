#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	ll t, n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		ll arr[n+1];
		for(int i=0;i<n;i++) cin>>arr[i];
		
		sort(arr, arr+n);
	
		int cnt=0;
		int flag = 0;
		for(int i=0; i<n; i++){
			if(arr[i]<=k/2){
				cnt++;
				if(cnt<=n/2)arr[i] = 1;
				else flag = 1;
				//cout<<cnt<<" fjdfk"<<endl;
			}
			if(flag or arr[i]>k/2) arr[i] = 0;
		}
		
		for(int i=0;i<n;i++){
			if(i) cout<<" "<<arr[i];
			else cout<<arr[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}
