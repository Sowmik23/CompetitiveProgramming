#include <bits/stdc++.h>
using namespace std;

int parent[100005];

struct st{
	int a,b,c;
} arr[100005];

bool comp(st x,st y )
{
	return x.c<y.c;
}

void init(int n)
{
	for(int i=0;i<=n;i++)
	{
		parent[i]=-1;
	}
}

int find(int x)
{
	if(parent[x]==-1) return x;
	return parent[x]=find(parent[x]);
}

int main()
{
	int test,n,m,A,cas=1;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&m,&A);
		init(n);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
		}
		int airport=n;
		
		sort(arr,arr+m,comp);
		int sum=0;
		for(int i=0;i<m;i++)
		{
			//if(arr[i].c>=A) break;
			int xx=find(arr[i].a);
			int yy=find(arr[i].b);
			
			if(xx!=yy and arr[i].c<A)
			{
				parent[xx]=yy;
				sum+=arr[i].c;
				if(airport>1) airport--;
			}
		}
		cout<<"Case #"<<cas++<<": "<<sum+(airport*A)<<" "<<airport<<endl;
	}
	
	return 0;
}
