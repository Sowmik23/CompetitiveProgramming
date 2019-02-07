#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int> 
#define INF 1000000

int coin[100];
pii visited[100][10000];

pii dp(int price,int i)
{
	if(price<=0) return make_pair(0,0);
	if(i<0) return make_pair(INF,INF);

	if(visited[i][price].first!=0) return visited[i][price];
	
	//if(visited[i][price].first==0)
	//{
		visited[i][price] = dp(price-coin[i],i-1);
		visited[i][price].first += coin[i];
		visited[i][price].second++;
		visited[i][price] = min(visited[i][price],dp(price,i-1));
	//}
	return visited[i][price];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t,price,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&price,&n);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=price;j++)
			{
				visited[i][j].first = 0;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&coin[i]);
		}
		
		pii k = dp(price,n-1);
	
		printf("%d %d\n",k.first,k.second);
	}
	
	return 0;
}
