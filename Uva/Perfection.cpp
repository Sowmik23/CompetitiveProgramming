#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t=1;
	while(scanf("%d",&n))
	{
		if(n==0) 
		{
		    printf("END OF OUTPUT\n");	
			break;
		}
		int ans=0,abun=0;
		
		for(int i=1;i<=n/2;i++)
		{
			if(n%i==0) ans+=i;
			if(ans>n)
			{
				abun = 1;
				 break;
			}
		}
		//cout<<ans<<endl;
		if(t==1) printf("PERFECTION OUTPUT\n");
		if(ans<n) printf("%5d  DEFICIENT\n",n);
		else if(ans==n) printf("%5d  PERFECT\n",n);
		else  printf("%5d  ABUNDANT\n",n);
		t++;
	}
	
	return 0;
}
