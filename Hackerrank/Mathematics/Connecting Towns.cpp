#include <bits/stdc++.h>

using namespace std;

//Total number of routes from T1 to Tn modulo 1234567
//Combination- permutation

int main()
{
	long long int t, n, x;
	cin>>t;
	while(t--){
		cin>>n;
		int res = 1;
		for(int i=0;i<n-1;i++) 
		{
			cin>>x;
			res*=x;
			res = res%1234567;
		}
		cout<<res<<endl;
	}
	
	
	return 0;
}
