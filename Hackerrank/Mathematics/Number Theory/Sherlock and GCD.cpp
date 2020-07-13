#include <bits/stdc++.h>

using namespace std;


//sub set GCD() yes/no output

int main(){
	
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n];
		
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		
		int flag=0;
		int d, k ;
		for(int i=0;i<n-1;i++){
			k = arr[i];
			if(arr[i]!=1) {
			 	d = __gcd(k, arr[i+1]);
			 //	cout<<d<<endl;
			 	if(d==1) {
					flag=1;
					break;
				}
			}
			else if(arr[i]==1){
				flag=1;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
