#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t, n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		
		int mx = 0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int x = i&j;
				if(mx<x and x<k) mx = x;
			}
		}
		cout<<mx<<endl;
	}
	
	return 0;
}
