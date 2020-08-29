#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	
	double mean = double(sum)/n;
	cout<<mean<<endl;
	
	sort(arr, arr+n);
	int x1, x2;
	double mod;
	if(n%2==0){
		x1 = (n-1)/2;
		x2 = n/2;
		mod = (arr[x1] + arr[x2])/2.0;
	}
	else mod = arr[n/2];
	
	cout<<mod<<endl;
	
	int value;
	int mx = 0, cnt = 1;
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1] )cnt++;
		if(mx<cnt){
			mx = cnt;
			value = arr[i];
		}
		else {
			cnt = 1;
		}
	}
	if(mx ==1) cout<<arr[0]<<endl;
	else cout<<value<<endl;
	
	return 0;
}
