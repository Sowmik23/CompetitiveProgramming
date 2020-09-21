#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 


int main(){
	
	ll t, n, k;
	
	cin>>t;
	while(t--){
		cin>>n>>k;
		
		//print first 3 digits
		double x = k*log10(n);
		///cout<<x<<" value of x"<<endl;
		///cout<<floor(x)<<" floor of x"<<endl;
		///cout<<x- floor(x) + 3 - 1<<endl;
		///cout<<pow(10, x- floor(x) + 3 - 1)<<" pow.."<<endl;
		double y = floor(pow(10, x- floor(x) + 3 - 1));
		cout<<y<<"...";
		
		//last three digits
		ll res = 1;
		while(k>0){
			if(k&1) res = (res%1000*n%1000)%1000;
			n = (n%1000*n%1000)%1000;
			k>>=1;
		}
		//cout<<setprecision(3)<<res<<endl;
		printf("%03lld\n", res);
	
	//string str = to_string(res);
	//int len = str.size();
	
	//cout<<str[0]<<str[1]<<str[2]<<"..."<<str[len-3]<<str[len-2]<<str[len-1]<<endl;
	
	}
	return 0;
}
