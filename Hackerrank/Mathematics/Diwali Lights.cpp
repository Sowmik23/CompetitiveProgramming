#include <bits/stdc++.h>

using namespace std;

//how many different patterns of light can the
// serial light bulb set produce


int main(){
	
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int res = 1;
		for(int i=1;i<=n;i++) 
		{
			res*=2;
			res = res%100000;
		}
		cout<<res-1<<endl;
	}
	
	return 0;
}
