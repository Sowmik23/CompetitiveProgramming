#include <bits/stdc++.h>

using namespace std;

//series

int main()
{
	long long t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long res = 0;
		/*for(long long i=1;i<=n;i++){
			res += (2*i-1)%10000000007;
		}*/
		n = n%1000000007;
		res = (n*n)%1000000007;
		cout<<res<<endl;
	}
	
	return 0;
}
