#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	// your code goes here
	int t;
	cin>>t;
	ll n;
	while(t--){
	    ll res=0;
	    cin>>n;
	    while(n/10){
	        int x = n%10;
	        res = res*10 + x;
	        n/=10;
	    }
	    res = res*10 + n;
	    cout<<res<<endl;
	}
	
	return 0;
}
