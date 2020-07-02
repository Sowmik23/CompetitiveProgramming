#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

map<int,string>mp1;
int AdjMatrix[105][105];

void initialize(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) AdjMatrix[i][j]=0;
			else AdjMatrix[i][j]=INF;
		}
	}
}

int main()
{
	int n,m,src,dest,cost;;
	string str;
	for(int test=1;;test++)
	{
		scanf("%d%d",&n,&m);
		if(n==0) break;
		initialize(n);
		mp1.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>str;
			mp1[i]=str;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&src,&dest,&cost);
			AdjMatrix[src][dest]=AdjMatrix[dest][src]=cost;
		}
		
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(AdjMatrix[i][j]>AdjMatrix[i][k]+AdjMatrix[k][j])
					{
						AdjMatrix[i][j]=AdjMatrix[i][k]+AdjMatrix[k][j];
					}
				}
			}
		}
		int ans,res=INF;
		for(int i=1;i<=n;i++)
		{
			int sum=0;
			for(int j=1;j<=n;j++)
			{
				 sum+=AdjMatrix[i][j];
			}
			if(res>sum)
			{
				res=sum;
				ans=i;
			}
		}
		printf("Case #%d : ",test);
		cout<<mp1[ans]<<endl;;
	}
	
	return 0;
}
