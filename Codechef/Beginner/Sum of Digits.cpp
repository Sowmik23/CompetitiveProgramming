#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	int t;
	cin>>t;
	ll x;
	while(t--){
	    cin>>x;
	    
	    ll sum = 0;
	    while(x/10){
	        sum+=x%10;
	        x = x/10;
	    }
	    sum+=x;
	    cout<<sum<<endl;
	}
	
	return 0;
}
