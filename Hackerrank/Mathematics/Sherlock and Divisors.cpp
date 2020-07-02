#include <bits/stdc++.h>

using namespace std;


int main(){
	
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		int cnt=0;
		for(int i=2;i*i<=n;i++){
			if(n%i==0 and i%2==0){
				cnt++;
			}
			if(n%(n/i)==0 and (n/i)%2==0 and (n/i)!=i) cnt++;
		}
		if(n%2==0) cnt++;
		
		cout<<cnt<<endl;
		
	}
	
	return 0;
}
