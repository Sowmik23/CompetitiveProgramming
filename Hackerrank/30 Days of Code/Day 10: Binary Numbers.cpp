#include <bits/stdc++.h>
using namespace std;

//finding maximum number of consequtive 1's of a decimal number's
//binary represtation

#define ll long long 

int main(){
	
	ll n;
	cin>>n;
	
	int cnt =0;
	while(n!=0){
		n = (n&(n<<1));
		cnt++;
	}
	cout<<cnt<<endl;
	
	return 0;
}
