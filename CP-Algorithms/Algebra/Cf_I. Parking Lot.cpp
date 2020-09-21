#include <bits/stdc++.h>
using namespace std;

//incomplete

typedef long long ll;

ll permutation(int k){
	ll res = 1;
	for(int i=2;i<=k;i++) res*=i;
	
	return res;
}


int main(){
	
	int n;
	cin>>n;
	
	int k = 2*n - 2;
	
	cout<<permutation(k)<<endl;
	
	
	return 0;
}
