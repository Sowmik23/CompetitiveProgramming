#include <bits/stdc++.h>
using namespace std;

//vector<pair<pair<int,int> ,int> >v1; //node,node,cost    //sabdhane ekhane sobkisui 1 theke suru//
int parent[1000005];

struct st{
	int a,b,c;
} arr[1000005];

bool comp(st x,st y)
{
	return x.c<y.c;
}

void init(int n)
{
	for(int i=1;i<=n;i++)
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
	int n,m,aa,bb,cc,k,cas=0;
	while(scanf("%d",&n) !=EOF) 
	{
		init(n);
		int total=0;
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&aa,&bb,&cc);  
			total+=cc;
		}
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
		}
		scanf("%d",&m);
		for(int i=k+1;i<=k+m;i++)
		{
			scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
		}
		sort(arr+1,arr+(k+m),comp);  
		
		int sum=0;
		for(int i=1;i<=(k+m);i++)
		{
			int xx=find(arr[i].a);
			int yy=find(arr[i].b);
			
			if(xx!=yy)
			{
				parent[xx]=yy;
				sum+=arr[i].c;
				//v1.push_back( { {arr[i].a,arr[i].b } , arr[i].c } );
			}
		}
		if(cas) cout<<endl;
		cout<<total<<endl<<sum<<endl;
		cas++;
	}
	
	return 0;
}
