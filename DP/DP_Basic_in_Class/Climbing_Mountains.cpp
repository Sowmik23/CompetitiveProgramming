#include <bits/stdc++.h>
using namespace std;

int visited[1000][1000];						/*Here you can move left, left-upper corner and upper */

long long dp(long long int x,long long int y)
{
	if(x==1 and y==1 ) return 1;
	if(x<1 or y<1) return 0;
	if(visited[x][y]!=0) return visited[x][y];
	
	//visited[x][y]=1;
	return visited[x][y] = dp(x-1,y) + dp(x-1,y-1) + dp(x,y-1);
}

int main()
{
	int n;
	scanf("%d",&n);
	
	long long ans = dp(n,n);
	printf("Number of ways to move from (%d,%d) to (1,1) is: %lld\n",n,n,ans);
	
	return 0;
}
