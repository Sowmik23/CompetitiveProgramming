#include <bits/stdc++.h>
using namespace std;

int n,k,arr[10009],visited[10009][10009],ans[10009][10009];

int dp(int i,int total)
{
	int res1,res2;
	if(i>n) return 0;
	
	if(i==n)
	{
		if(total%k==0) return 1;
		else return 0;
	}
	if(visited[i][total]!=-1) return visited[i][total];
	
	int sum = arr[i] + total;
	if(sum<0) sum = (sum%k)+k ;
	res1 = dp(i+1,sum%k);
	
	sum = arr[i] - total;
	if(sum<0) sum = (sum%k)+k ;
	res2 = dp(i+1,sum%k);
	
	return visited[i][total] = max(res1,res2);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		memset(visited,-1,sizeof(visited));
	//cout<<dp(0,0)<<endl;	
	
		if(dp(0,0)!=0) printf("Divisible\n");
		else printf("Not divisible\n");
	}
	
	return 0;
}
