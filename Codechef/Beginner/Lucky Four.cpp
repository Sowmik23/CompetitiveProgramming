#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	// your code goes here
	
	ll t, n;
	cin>>t;
	while(t--){
	    
	    cin>>n;
	    ll cnt = 0;
	    while(n/10){
	        int x = n%10;
	        if(x==4) cnt++;
	        n/=10;
	    }
	    if(n==4) cnt++;
	    cout<<cnt<<endl;
	}
	
	return 0;
}
