#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,n,m,a,b,arr[900000];
	scanf("%lld",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld%lld",&n,&m);
		for(int j=0;j<n;j++) scanf("%lld",&arr[j]);
		cout<<"Case "<<i<<":"<<endl;
		while(m--)
		{
			scanf("%lld%lld",&a,&b);
			long long int x=lower_bound(arr,arr+n,a)-arr;
			long long int y=upper_bound(arr,arr+n,b)-arr;
			printf("%lld\n",y-x);
		}
	}
	
	return 0;
}
