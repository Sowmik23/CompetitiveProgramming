#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	
	int t;
	cin>>t;
	ll n;
	while(t--){
	    cin>>n;
	    
	    int last = n%10;
	    int len = log10(n);
	    
	    int first = floor(n*pow(10, -1*len));
	    
	    //cout<<first<<" "<<last<<endl;
	    
	    cout<<first+last<<endl;
	}
	
	return 0;
}
