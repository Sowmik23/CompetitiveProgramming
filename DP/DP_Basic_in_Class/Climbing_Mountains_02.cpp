#include <bits/stdc++.h>
using namespace std;

int g[10000][10000];
int visited[1000][1000];						/*Here you can move left, left-upper corner and upper */
long long a,b,c,m;											/*But here you have to determine কোন পথে গুপ্তধন বেশি  */

long long dp(long long int x,long long int y)
{
	if(x==1 and y==1 ) return visited[x][y];
	if(x<1 or y<1) return 0;
	if(visited[x][y]!=0) return visited[x][y];
	
	a = dp(x-1,y) + g[x-1][y-1];
	b = dp(x-1,y-1) + g[x-1][y-1];
	c = dp(x,y-1) + g[x-1][y-1];
	m = max(a,b);
	return visited[x][y] = max(m,c);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	
	long long ans = dp(n,n);
	printf("Maximum guptodhone to go from (%d,%d) to (1,1) is: %lld\n",n,n,ans);
	
	return 0;
}

