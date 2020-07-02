#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int AdjMatrix[100][100],parent[100][100];

void initialize(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			parent[i][j]=i;
			if(i==j) AdjMatrix[i][j]=0;
			else AdjMatrix[i][j]=INF;
		}
	}
}

void printpath(int src,int dest)
{
	if(src==dest) 
	{
		cout<<" "<<src;
		return ;
	}
	printpath(src,parent[src][dest]);
	cout<<" "<<dest;
}

int main()
{
	int n,m,v,w,src,dest;
	for(int test=1;;test++)
	{
		scanf("%d",&n);
		if(n==0) break;
		initialize(n);
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d%d",&v,&w);
				AdjMatrix[i][v] = w;
			}
		}
		
		
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(AdjMatrix[i][j]>AdjMatrix[i][k] + AdjMatrix[k][j])
					{
						AdjMatrix[i][j] = AdjMatrix[i][k] + AdjMatrix[k][j];
						parent[i][j] = parent[k][j];
					}
				}
			}
		}
		scanf("%d%d",&src,&dest);
		
		cout<<"Case "<<test<<": Path =";					
		printpath(src,dest);
		cout<<"; "<<AdjMatrix[src][dest]<<" second delay"<<endl;
	}
	
	return 0;
}
