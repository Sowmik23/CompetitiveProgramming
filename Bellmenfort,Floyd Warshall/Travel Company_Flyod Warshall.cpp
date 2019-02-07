#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int AdjMatrix[1000][1000];

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
	int test,n,m,p,src,dest,income,expences;
	scanf("%d",&test);
	for(int ii=1;ii<=test;ii++)
	{
		scanf("%d%d%d",&n,&m,&p);
		initialize(n);
		
		while(m--)
		{
			scanf("%d%d%d%d",&src,&dest,&income,&expences);
			AdjMatrix[src][dest]=p*expences - income;  /* as income/expences = p; */
		}
		
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(AdjMatrix[i][j] > (AdjMatrix[i][k] + AdjMatrix[k][j]))
					{
						AdjMatrix[i][j] = (AdjMatrix[i][k] + AdjMatrix[k][j]);
					}
				}
			}
		}
		
		/* this checks if negative cycle exists.....*/
		
		int has_Negative_Cycle=0;
		for(int i=0;i<n;i++)
		{
			if(AdjMatrix[i][i]<0)
			{
				has_Negative_Cycle=1;
				break;
			}
		}
		cout<<"Case "<<ii;
		if(has_Negative_Cycle==1) cout<<": YES"<<endl;
		else cout<<": NO"<<endl;
	}
	
	return 0;
}

