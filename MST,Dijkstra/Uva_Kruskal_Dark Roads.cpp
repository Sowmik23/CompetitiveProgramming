#include <bits/stdc++.h>
using namespace std;

//vector<pair<pair<int,int> ,int> >v1;
int parent[200010];

struct st{
	int a,b,c;
};

bool comp(st x,st y)
{
	return x.c<y.c;
}

void init(int n)
{
	for(int i=0;i<n;i++) parent[i]=-1;
}

int find(int parent[],int x)
{
	if(parent[x]==-1) return x;
	return parent[x]=find(parent,parent[x]);
}

int main()
{
	st arr[200010];
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0 and m==0) break;
		init(n);
		int sum=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
			sum+=arr[i].c;
		}
		sort(arr,arr+m,comp);
		int total=0;
		for(int i=0;i<m;i++)
		{
			int xx=find(parent,arr[i].a);
			int yy=find(parent,arr[i].b);
			
			if(xx!=yy)
			{
				parent[xx]=yy;
				total+=arr[i].c;
				//v1.push_back( { {arr[i].a,arr[i].b},arr[i].c } );
			}
		}
		cout<<sum-total<<endl;
	}
	
	return 0;
}
