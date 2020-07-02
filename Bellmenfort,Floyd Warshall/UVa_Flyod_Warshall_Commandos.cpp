#include <bits/stdc++.h>   //Interesting problem
using namespace std;
#define INF 1e9

int AdjMatrix[110][110];

void initialize(int n)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==j) AdjMatrix[i][j]=0;
			else AdjMatrix[i][j]=INF;
		}
	}
}

int main()
{
	int t,n,r,u,v,s,d;
	scanf("%d",&t);
	for(int l=1;l<=t;l++)
	{
		scanf("%d%d",&n,&r);
		initialize(n);
		for(int i=0;i<r;i++)
		{
			scanf("%d%d",&u,&v);
			AdjMatrix[u][v]=1;   //as each cost is 1;
			AdjMatrix[v][u]=1;
		}
		
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(AdjMatrix[i][j] > AdjMatrix[i][k] + AdjMatrix[k][j])
					{
						AdjMatrix[i][j] = AdjMatrix[i][k] + AdjMatrix[k][j];
					}
				}
			}
		}
		int min_time=0;
		scanf("%d%d",&s,&d);
		for(int i=0;i<n;i++)
		{
			if(AdjMatrix[s][i]!=INF and AdjMatrix[i][d]!=INF)
			{
				min_time= max(min_time,(AdjMatrix[s][i]+AdjMatrix[i][d]));
			}
		}
		
		
		printf("Case %d: %d\n",l,min_time);
	}
	
	return 0;
}
