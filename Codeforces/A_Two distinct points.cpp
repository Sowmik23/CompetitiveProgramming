#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int l1,l2,r1,r2;
	int q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		
		if(r1!=l2)
		{
			printf("%lld %lld\n",r1,l2);
		}
		else if(r1==l2) {
			printf("%lld %lld\n",r1,l2+1);
			
		}	
	
	}
	
	return 0;
}
