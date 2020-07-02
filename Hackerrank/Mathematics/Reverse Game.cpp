#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t, n, k, ans;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int arr[n];
		int j=0, l=0;
		for(int i=0;i<n;i++){
			if(i%2==0) {
				arr[i] = n-l-1;
				l++;
			}
			else {
				arr[i]= j;
				j++;
			}
			if(arr[i] ==k) ans = i;
		} 
		//for(int i=0;i<n;i++) cout<<arr[i]<<" ";
		cout<<ans<<endl;
	}
	
	return 0;
}
