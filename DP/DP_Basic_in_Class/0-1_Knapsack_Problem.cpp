#include <bits/stdc++.h>
using namespace std;

int visited[1000][10000];

int dp(int w,int val[],int weight[],int n)
{
	if(n==0 or w==0) return 0;
	if(visited[w][n]!=0) return visited[w][n];
	
	if(weight[n-1]>w) 
	{
		visited[w][n] = dp(w,val,weight,n-1);
	}
	else 
	{
		visited[w][n] = max(val[n-1] + dp(w-weight[n-1],val,weight,n-1) , dp(w,val,weight,n-1));
	}
	return visited[w][n];
}

int main()			//w--->weight of the knapsack //
{
	int w,n,val[10000],weight[10000];
	scanf("%d%d",&w,&n);
	for(int i=0;i<n;i++) scanf("%d",&weight[i]);
	for(int i=0;i<n;i++) scanf("%d",&val[i]);
	
	printf("%d\n",dp(w,val,weight,n));
	
	return 0;
}
