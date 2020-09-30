#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, k,t;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		int arr[n+1];
		for(int i=0;i<n;i++) cin>>arr[i];
		
		sort(arr, arr+n);
		int cnt=0;
		int x = arr[0];
		for(int i=1;i<n;i++){
			//for(int j=i+1;j<n; j++) {
			int y = arr[i];
				while(1) {
					y += x;
					if(y<=k) cnt++;
					else break;
					//cout<<y<<" " <<cnt<<endl;
				}
			//}
		}
		cout<<cnt<<endl; 	
	}
	
	
	return 0;
}
