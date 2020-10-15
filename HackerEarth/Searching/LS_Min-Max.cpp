#include <bits/stdc++.h>
using namespace std;


typedef long long ll;



int main(){
	
	ll n;
	cin>>n;
	ll arr[n+5];
	ll sum=0;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
		sum+=arr[i];
	}
	
	sort(arr, arr+n);
	
	cout<<sum-arr[n-1]<<" "<<sum-arr[0]<<endl;
	
	return 0;
}
