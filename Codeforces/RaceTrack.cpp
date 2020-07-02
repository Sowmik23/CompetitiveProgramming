#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,m,mx;
	scanf("%lld%lld",&n,&m);
	mx = max(n,m);
	while(1)
	{
		if(mx%n==0 and mx%m==0)
		{ cout<<mx<<endl; break;}
		else mx++;
	}
	
	return 0;
}

