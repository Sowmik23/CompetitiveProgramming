#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int n, m;
	cin>>n;
	int arr[n+4];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>m;
	int crr[m+5];
	int mx = 0;
	for(int i=0;i<m;i++){
		cin>>crr[i];
		mx = max(crr[i], mx);
	}
	
	int b[mx+6] = {0};
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int k = crr[j] - arr[i];
			//cout<<k<<" ";
			b[k]++;
		}
	}
	//cout<<endl;
	
	for(int i=1;i<mx;i++){
		if(b[i]==n) cout<<i<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
