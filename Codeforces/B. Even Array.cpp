#include <bits/stdc++.h>

using namespace std;

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
		int cnt1=0, cnt2=0;
		
		for(int i=0;i<n;i++){
			if(i%2==0){
				if(arr[i]%2!=0) cnt1++;
			}
			else {
				if(arr[i]%2==0) cnt2++;
			}
		}
		
		//cout<<cnt1<<" " <<cnt2<<endl;
		if(cnt1==cnt2) cout<<cnt1<<endl;
		else cout<<"-1"<<endl;
		
	}
	
	return 0;
}
