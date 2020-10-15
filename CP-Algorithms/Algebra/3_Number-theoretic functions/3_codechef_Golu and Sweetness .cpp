#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, q, l, r;
	cin>>n>>q;
	
	int arr[n+4];
	arr[0] = 0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i] = (arr[i]==3 || arr[i]==4 || arr[i]==6);
		arr[i] += arr[i-1];
	}
	//for(int i=0;i<n;i++) cout<<arr[i];
	
	while(q--){
		cin>>l>>r;
		
		int ans = arr[r] - arr[l-1];
		cout<<ans<<endl;
	}
	
	return 0;
}

