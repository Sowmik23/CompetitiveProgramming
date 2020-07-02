#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

pair<int,int> pa;
int AdjMatrix[105][105];

void initialize()
{
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		{
			if(i==j) AdjMatrix[i][j]=0;
			else AdjMatrix[i][j]=INF;
		}
	}
}

int main()
{
	int a,b,mx,test=1;
	while(1)
	{
		initialize();
		int mx=-1;
		scanf("%d%d",&a,&b);
		if(a!=0 and b!=0)
		{
			mx=max(mx,max(a,b));
			AdjMatrix[a][b]=1;
			while(scanf("%d%d",&a,&b))
			{
				if(a==0 and b==0) break;
				mx=max(mx,max(a,b));
				AdjMatrix[a][b]=1;
			}
			int n=mx;
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						if(AdjMatrix[i][j] > AdjMatrix[i][k] + AdjMatrix[k][j])
						{
							AdjMatrix[i][j] = AdjMatrix[i][k] + AdjMatrix[k][j];
						}
					}
				}
			}
			int cnt=0;
			double sum=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j and AdjMatrix[i][j]!=INF)
					{
						 sum+=AdjMatrix[i][j];
						 cnt++;
					 }
				}
			}
			double ans=sum/cnt;
			printf("Case %d: average length between pages = %.3lf clicks\n",test++,ans);	
		}
		else if(a==0 and b==0) break;	
	}
	
	return 0;
}
