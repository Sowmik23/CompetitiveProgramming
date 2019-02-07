#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,q,p,x,y;
		scanf("%lld%lld",&n,&q);
		
		long long int a[n],i,d,l;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(l=0;l<q;l++)
		{
			scanf("%lld%lld%lld",&p,&x,&y);
			
			if(p==1)
			{
				sort(a,a+n);
				for(i=0;i<n;i++)
				{
					if(a[i]<=x)
					{
						d=a[i];
						a[i]=d-y;
					}
					else break;	
				}
			}
			else if(p==2)
			{
				sort(a,a+n);
				for(i=n-1;i>=0;i--)
				{
					if(a[i]>=x)
					{
						d=a[i];
						a[i]=d+y;
					}
					else break;	
				}	
			}	
		}
		for(i=0;i<n;i++)
		{
			printf("%lld",a[i]);
			if(i!=n-1) cout<<" ";
		}
		printf("\n");
	}
	
	return 0;
}
