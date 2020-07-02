#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,a,b,x;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		/*while(a!=b)
		{
			if(a>b) 
			{
				a-=b;
			}
			else b-=a;
		}*/
		x = __gcd(a,b);
		if(x==1) printf("Nao\n");
		else printf("Sim\n");
	}
		
	return 0;
}
