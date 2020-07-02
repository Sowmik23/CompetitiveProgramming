#include <bits/stdc++.h>
using namespace std;

int n,k,arr[100005],visited[10000][10000];

int dp(int i,int sum)
{
	if(i==n and sum==0) return 1;
	if(i>=n) return 0;
		
	if(visited[i][sum]!=0) return visited[i][sum];
	//cout<<sum<<" fsdsdf "<<endl;
	int x = arr[i]/k;
	x++;
	
	int a = dp(i+1,(sum+arr[i]+x*k)%k);
	int b = dp(i+1,(sum-arr[i]+x*k)%k);
	//cout<<a<<" "<<b<<endl;
	visited[i][sum] = max(a,b);
	return visited[i][sum];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(visited,0,sizeof(visited));
		
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		if(dp(0,0)) printf("Divisible\n");
		else printf("Not divisible\n");
	}
	
	return 0;
}
