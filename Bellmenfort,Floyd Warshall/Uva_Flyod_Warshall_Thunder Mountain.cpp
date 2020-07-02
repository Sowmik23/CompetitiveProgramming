#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

double AdjMatrix[105][105];

struct st{
	int x ,y;
}arr[1000];

void initialize(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) AdjMatrix[i][j]=0.0;
			else AdjMatrix[i][j]=INF;
		}
	}
}

double distance(int x1,int y1,int x2,int y2)
{
	double xx=x1-x2;
	double yy=y1-y2;
	double ans=sqrt(xx*xx+yy*yy);
	return ans;
}

int main()
{
	int test,n;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		scanf("%d",&n);
		initialize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&arr[i].x,&arr[i].y);
		}
		double cost;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				cost = distance(arr[i].x,arr[i].y,arr[j].x,arr[j].y);
				if(cost>10.0) 
				{
					AdjMatrix[i][j]=INF;
					AdjMatrix[j][i]=INF;
				}
				else 
				{
					AdjMatrix[i][j]=cost;
					AdjMatrix[j][i]=cost;
				}
			}
		}
		
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(AdjMatrix[i][j] > AdjMatrix[i][k] + AdjMatrix[k][j] )
					{
						AdjMatrix[i][j] = AdjMatrix[i][k] + AdjMatrix[k][j] ;
					}
				}
			}
		}
		double mx=-100;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(AdjMatrix[i][j] > mx )
				{
					mx = AdjMatrix[i][j];
				}
			}
		}
		if(mx==INF) printf("Case #%d:\nSend Kurdy\n",t);
		else printf("Case #%d:\n%.4lf\n",t,mx);
		cout<<endl;
	}
	
	return 0;
}
