
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
	
	ll n, k, x, cnt=0;
	cin>>n>>k;
	
	while(n--){
		cin>>x;
		if(x%k==0) cnt++;
	}
	cout<<cnt<<endl;
	
	return 0;
}
