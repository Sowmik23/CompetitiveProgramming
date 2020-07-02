#include <bits/stdc++.h>
using namespace std;

int n,m;
long long arr[1000000],visited[10000][100];

int dp(int i,int total)
{
	int res1,res2;
	
	if(i>n) return 0;
	
	if(i==n)
	{
		if(total%m==0) return 1;
		else return 0;
	}
	if(visited[i][total]!=-1) return visited[i][total];
	
	int sum=arr[i] + total;
	if(sum<0) sum = (sum%m) + m;
	res1 = dp(i+1,sum%m);
	
	sum = arr[i]-total;
	if(sum<0) sum = (sum%m) + m;
	res2 = dp(i+1,sum%m);
	
	return visited[i][total] = max(res1,res2);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	
	memset(visited,-1,sizeof(visited));
	
	//cout<<dp(0,0)<<endl;
	
	if(dp(0,0)!=0) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
