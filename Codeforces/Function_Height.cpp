#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,k,ans;
	scanf("%lld%lld",&n,&k);
	ans = k/n;
	if(k%n!=0)
	{
		ans++;
	}
	cout<<ans<<endl;
	
	return 0;
}
