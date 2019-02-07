#include <bits/stdc++.h>
using namespace std;

#define mx 1e9

int n,arr[10009],brr[10009];
long long visited[10009][10009];

long long dp(int start,int end)
{
	if(start==end) return 0;
	if(visited[start][end]!=-1) return visited[start][end];
	
	visited[start][end] = mx;
	for(int i=start;i<end;i++)
	{
		visited[start][end] = min( visited[start][end], dp(start,i)+dp(i+1,end)+arr[start]*brr[end]*brr[i]);
	}
	return visited[start][end];
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",arr+i,brr+i);  //New style ...evabeo array input neoa jay....:0)  ///
	}
	
	memset(visited,-1,sizeof(visited));
	
	cout<<dp(0,n-1)<<endl;
	
	return 0;
}
