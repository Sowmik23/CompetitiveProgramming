#include <bits/stdc++.h>

using namespace std;

#define ll long long 

ll cnt = 0;

int ifPossible(ll n){
	
	if(n==1) return cnt;
	//cout<<n<<endl;
	if(n<=0) return -1;
	cnt++;
	if(n%6==0) return ifPossible(n/6);
	else return ifPossible(n*2);
}


int main(){
	
	ll t, n;
	cin>>t;
	while(t--)
	{
		cnt=0;
		cin>>n;
		ll ans = ifPossible(n);
		
		
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
