#include <bits/stdc++.h>
using namespace std;




int main(){
	
	int arr[10];
	int sum = 0;
	for(int i=1;i<=8;i++) {
		cin>>arr[i];
		sum+=arr[i];
	}
	
	int p ;
	int a, b;
	cin>>p;
	
	map<int, int> mp;
	map<int, int> ::iterator it;
	
	int opponnent[10];
	for(int i=1;i<=8;i++) opponnent[i] = 0;
	
	while(p--){
		cin>>a>>b;
		
		opponnent[a] += arr[b];
		opponnent[b] +=arr[a];
		
		mp[a] = b;
		
		if(arr[a]>arr[b]){
			sum-=arr[b];
		}
		else {
			sum-=arr[a];
		}
	}
	
	int ans = 0;
	for(int i=1;i<=8;i++){
		if(opponnent[i]>arr[i]){
			ans+=opponnent[i];
		}
		else {
			ans+=arr[i];
		}
	}
	
	
	cout<<ans<<endl;

	
	return 0;
}




