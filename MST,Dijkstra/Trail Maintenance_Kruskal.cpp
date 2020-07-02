#include <bits/stdc++.h>
using namespace std;

int parent[209],cnt,n,m;

struct st{
	int src,dest,cost;
} arr[6009];

bool comp(st x,st y)
{
	return x.cost<y.cost;
}

void init()
{
	for(int i=0;i<=n;i++) parent[i]=-1;
}

int find(int x)
{
	if(parent[x]==-1) return x;
	return parent[x]=find(parent[x]);
}

int kruskal()
{
	init();
	sort(arr,arr+cnt,comp);
	int sum=0;
	int k=0,d=-1;
	
	for(int j=0;j<cnt;j++)
	{
		int xx= find(arr[j].src);
		int yy=find(arr[j].dest);
		if(xx!=yy)
		{
			parent[xx]=yy;
			sum+= arr[j].cost;
			k++;
		}
		else d=j;
	}
	if(d!=-1) arr[d]=arr[--cnt];
	if(k==n-1) return sum;
	else return -1;	
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		scanf("%d%d",&n,&m);
		printf("Case %d:\n",t);
		cnt=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&arr[cnt].src,&arr[cnt].dest,&arr[cnt].cost);
			
			cnt++;
			
			printf("%d\n",kruskal());
		}		
	}
	
	return 0;
}
