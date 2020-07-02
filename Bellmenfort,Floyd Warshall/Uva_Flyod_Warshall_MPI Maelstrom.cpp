#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int AdjMatrix[105][105];

void initialize(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) 
			{
				AdjMatrix[i][j]=0;
				AdjMatrix[j][i]=0;
			}
			else 
			{
				AdjMatrix[i][j]=INF;
				AdjMatrix[j][i]=INF;
			}	
		}
	}
}

int main()
{
	int n,value;
	string str;
	scanf("%d",&n);
	initialize(n);
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			cin>>str;
			if(str!="x")
			{
				stringstream ss(str);
				ss>>value;
				AdjMatrix[i][j]=value;
				AdjMatrix[j][i]=value;
			}
			//else AdjMatrix[i][j]=AdjMatrix[j][i]=INF;
		}
	}
	
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
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,AdjMatrix[1][i]);
	}
	cout<<ans<<endl;
	
	return 0;
}
