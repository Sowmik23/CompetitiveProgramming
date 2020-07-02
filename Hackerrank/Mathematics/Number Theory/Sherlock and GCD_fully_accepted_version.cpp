#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n];
		
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		
		bool divisor_exists = false;
		for(int i=2;i<=100000;i++){
			int cnt=0;
			for(int j=0;j<n;j++){
				if(arr[j]%i==0) cnt++;
			}
			
			if(cnt==n){
				divisor_exists = true;
				break;
			}
		}
		cout<<(divisor_exists ? "NO" : "YES")<<endl;
	}
	
	return 0;
}
