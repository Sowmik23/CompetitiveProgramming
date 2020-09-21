#include <bits/stdc++.h>
using namespace std;

#define ll long long 


int main(){
	
	ll n;
	cin>>n;
	
	while(n!=1){
		cout<<n<<" ";
		if(n%2==0) n = n/2;
		else n = n*3 + 1;
		//if(n<0) break;
	}
	cout<<1<<endl;
	
	return 0;
}








