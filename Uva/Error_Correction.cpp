#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,row,col;
	int arr[105][105];
	
	while(scanf("%d",&n))
	{
		if(n==0) break;
		int cnt=0;
		row =0,col=0;
		
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&arr[i][j]);
				sum+=arr[i][j];
			}
			if(sum%2!=0) 
			{
				cnt++;
				row = i;
			}
		} 
				
		for(int j=1;j<=n;j++)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				sum+=arr[i][j];
			}
			if(sum%2!=0) 
			{
				cnt++;
				col = j;
			}
		}
		if(cnt==0) printf("OK\n");
		else if(cnt==2 and row!=0 and col!=0) printf("Change bit (%d,%d)\n",row,col);
		else printf("Corrupt\n");
	}
	
	return 0;
}
