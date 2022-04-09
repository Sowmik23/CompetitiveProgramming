#include <bits/stdc++.h>
using namespace std;


///Time Complexity: O(logn)

int Pow(int x, int n, int mod){
	if(n==0) return 1;
	
	else if(n%2==0){
		int y = Pow(x, n/2, mod);
		return (y*y)%mod;
	}
	else return x%mod*Pow(x, n-1, mod)%mod;
}


int main(){
	
	int x = 2 , n = 14, mod = 1e9+7;
	
	int res = Pow(x, n, mod);
	cout<<res<<endl;
	
	return 0;
}
