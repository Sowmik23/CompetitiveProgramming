#include <bits/stdc++.h>
using namespace std;

int arr[3660];

int main()
{
	int t,n,h;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int cnt=0;
		
		scanf("%d",&h);
		for(int i=0;i<h;i++)
		{
			scanf("%d",&arr[i]);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(i%7==6 or i%7==0) continue;
			for(int j=0;j<h;j++)
			{
				if(i%arr[j]==0) 
				{
					cnt++;
					break;
				}
			}                                       ;
		}
		printf("%d\n",cnt);
	}
	
	return 0;
}
