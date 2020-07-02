#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t,a,f;
	scanf("%d",&t);
	for(int l=1;l<=t;l++)
	{
		scanf("%d%d",&a,&f);
		for(int i=1;i<=f;i++)
		{
			for(int j=1;j<=a;j++)
			{
				int p = j;
				for(int k=1;k<=j;k++)
				{
					printf("%d",p);
				}
				printf("\n");
			}
			for(int j=a-1;j>=1;j--)
			{
				int p=j;
				for(int k=j;k>=1;k--)
				{
					printf("%d",p);
				}
				if(l==t and i==f and j==1) break;
				printf("\n");
			}
			printf("\n");
		}
	}
	
	return 0;
}
