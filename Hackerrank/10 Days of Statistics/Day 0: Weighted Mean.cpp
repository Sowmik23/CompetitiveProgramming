#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	double sm=0, sum=0;
	cin>>n;
	int arr[n], weight[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) {
		cin>>weight[i];
		sm+=weight[i];
	}
	
	for(int i=0;i<n;i++){
		sum+=(arr[i]*weight[i]);
	}
	
	double ans = sum/sm;
	cout<<setprecision(1)<<fixed<<ans<<endl;
	
	
	return 0;
}
