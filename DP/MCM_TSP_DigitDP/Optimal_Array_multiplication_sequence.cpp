#include <bits/stdc++.h>
using namespace std;

#define mx 1e9

int n,arr[12],brr[12],visited[12][12],answer[12][12];


int dp(int start,int end)
{
	if(start==end) return 0;
	if(visited[start][end]!=-1) return visited[start][end];
	
	int res,ans = mx;
	
	for(int i=start;i<end;i++)
	{
		res = dp(start,i)+dp(i+1,end)+arr[start]*brr[end]*brr[i];
		if(res<ans)
		{
			ans = res;
			answer[start][end] = i;
			//cout<<i<<endl;
		}
	}
	return visited[start][end]=ans;
}

void print(int start,int end)
{
	if(start>end) return ;
	
	if(start==end) printf("A%d",start+1);
	else 
	{
		printf("(");
		print(start,answer[start][end]);
		printf(" x ");
		print(answer[start][end]+1,end);
		printf(")");
	}
}

int main()
{
	int test=1;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&arr[i],&brr[i]);
		}
		memset(visited,-1,sizeof(visited));
		memset(answer,0,sizeof(answer));
		
		//cout<<dp(0,n-1)<<endl;
		dp(0,n-1);
		
		printf("Case %d: ",test++);
		
		print(0,n-1);
		cout<<endl;
	}
	
	return 0;
}
