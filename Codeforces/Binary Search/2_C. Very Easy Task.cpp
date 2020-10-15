#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x, y;


bool good(ll time){
	ll k = time/x + time/y + 1;
	return k>=n;
}


int main(){
	cin>>n>>x>>y;
	
	if(n==1) cout<<min(x, y)<<endl;
	else {
		ll low=0, high=2e9, mid;
		while(low+1<high){
			mid = (low+high)/2;
			//cout<<low<<" "<<mid<<" "<<high<<endl;
			if(good(mid)) high = mid;
			else low = mid; 
		}
		//cout<<low<<" "<<mid<<" "<<high<<endl;
		cout<<high+min(x, y)<<endl;
	}
	
	return 0;
}
