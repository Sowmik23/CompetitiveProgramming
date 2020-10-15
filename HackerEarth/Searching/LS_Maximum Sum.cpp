#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

int main(){
	
	ll n;
	cin>>n;
	ll arr[n+2];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//-343 3 5 7
	
	sort(arr, arr+n, greater<int>());
	
	ll cnt=0;
	ll sum = 0;
	for(int i=0;i<n;i++){
		if(arr[i]>=0){
			sum+=arr[i];
			cnt++;
		}
		if(arr[i]<0 and cnt==0){
			sum =arr[i];
			cnt=1;
			break;
		}
	}
	cout<<sum<<" "<<cnt<<endl;
	
	return 0;
}
