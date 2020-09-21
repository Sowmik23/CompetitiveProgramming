#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

ll bigMod(ll n, ll pow){
	
	if(pow==0) return 1;
	ll res = bigMod(n, pow/2);
	
	if(pow%2==0) return (res%1000000007*res%1000000007)%1000000007;
	else return (res%1000000007*res%1000000007*n%1000000007)%1000000007;
}


int main(){
	
	int t;
	ll n;
	cin>>t;
	while(t--){
		ll res;
		cin>>n;
		
		///Here is the main trick of this problem
		//cout<<bigMod(3, n/3)<<endl;
		
		if(n<3) {
			cout<<n<<endl;
			continue;
		}
		else if(n%3==1){
			ll pow = (n-4)/3;
			res = 4*bigMod(3, pow);
		}
		else if(n%3==2) {
			ll pow = (n-2)/3;
			res = 2*bigMod(3, pow);
		}
		else res = bigMod(3, n/3);
		
		res = res%1000000007;
		
		cout<<res<<endl;
	}
	
	return 0;
}
