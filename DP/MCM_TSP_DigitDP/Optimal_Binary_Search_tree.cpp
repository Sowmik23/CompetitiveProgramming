#include <bits/stdc++.h>
using namespace std;

#define mx 1e9

int arr[300],freq[300],visited[300][300];

int sum(int a,int b)
{
	if(a>b) return 0;
	return freq[b]-freq[a-1];
}

int dp(int i,int j)
{
	if(i>=j) return 0;
	
	if(visited[i][j]!=-1) return visited[i][j];
	
	visited[i][j] = mx;
	for(int k=i;k<=j;k++)
	{
		visited[i][j] = min(visited[i][j], (dp(i,k-1)+dp(k+1,j)+sum(i,k-1)+sum(k+1,j)));
	}
	return visited[i][j];
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(int i=0;i<n;i++)
		{
			freq[i] = freq[i-1]+arr[i];
			//cout<<freq[i]<<" ";
		}
		//cout<<endl;
		memset(visited,-1,sizeof(visited));
		
		printf("%d\n",dp(0,n-1));
	}
	
	return 0;
}
