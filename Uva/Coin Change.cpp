#include <bits/stdc++.h>
using namespace std;

int arr[] ={50,25,10,5,1};
int visited[6][10000];

int dp(int i,int n)
{
	if(i>=5 || n<0) return 0;
	if(n==0) return 1;
	
	if(visited[i][n]!=-1) return visited[i][n];
	else return visited[i][n] =dp(i+1,n) + dp(i,n-arr[i]);
}

int main()
{
	int n;
	
	while(scanf("%d",&n) !=EOF)
	{
		memset(visited,-1,sizeof(visited));
		printf("%d\n",dp(0,n));
	}
	return 0;
}
