#include <bits/stdc++.h>

using namespace std;

//tag: gcd , find a list of array related gcd()



int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		
		cout<<arr[0]<<" ";
		
		for(int i=1;i<n;i++){
			cout<<(arr[i-1]*arr[i])/(__gcd(arr[i-1], arr[i]))<<" ";
		}
		cout<<arr[n-1]<<endl;
	}

	return 0;
}
