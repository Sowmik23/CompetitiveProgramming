#include <bits/stdc++.h>
using namespace std;


int hexa(int n){
	int sum=0;
	while(n>0){
		sum+=n%16;
		n/=16;
	}
	return sum;
}


int main(){
	
	int t, l, r;
	cin>>t;
	while(t--){
		cin>>l>>r;
		
		int cnt =0;
		for(int i=l;i<=r;i++){
			if(__gcd(i, hexa(i))>1) cnt++;
		}
		
		cout<<cnt<<endl;
	}
	
	
	return 0;
}
 
