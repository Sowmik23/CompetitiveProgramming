#include <bits/stdc++.h>
using namespace std;

vector<int>v1;
int parent[100005],visited[100005];
int v,e;
struct st{
	int start,end,cost;
}arr[1000];

bool comp(st x,st y)
{
	return x.cost<y.cost;
}

void init(int n)
{
	for(int i=0;i<=n;i++)
	{
		parent[i]=-1;
		//visited[i]=0;
	}
}

int find(int x)
{
	if(parent[x]==-1) return x;
	return parent[x]=find(parent[x]);
}

void secondMst(int i)
{
	for(int j=0;j<=v;j++) parent[j]=-1;
	int sum=0,cnt=0;
	for(int j=0;j<e;j++)
	{
		int x1=find(arr[j].start);
		int x2=find(arr[j].end);
		if(x1!=x2 and i!=j) 
		{
			parent[x1]=x2;
			sum+=arr[j].cost;
			cnt++;
		}
	}
	if(cnt==v-1) v1.push_back(sum);
}


int main()
{
	int test;
	scanf("%d",&test);
	for(int ii=1;ii<=test;ii++)
	{
		scanf("%d%d",&v,&e);
		init(v);
		for(int i=0;i<e;i++)
		{
			scanf("%d%d%d",&arr[i].start,&arr[i].end,&arr[i].cost);
			visited[i]=0;
		}
		sort(arr,arr+e,comp);
		int sum=0;
		int cnt=0;
		for(int i=0;i<e;i++)
		{
			int xx=find(arr[i].start);
			int yy=find(arr[i].end);
			if(xx!=yy)
			{
				parent[xx]=yy;
				sum+=arr[i].cost;
				visited[i]=1;
				cnt++;
			}
		}
		cout<<"Case #"<<ii<<" : ";
		if(cnt!=v-1)
		{
			cout<<"No way"<<endl;
			continue;
		}
		for(int i=0;i<e;i++)
		{
			if(visited[i]==1) secondMst(i);
		} 
		if(v1.size()>0)
		{
			sort(v1.begin(),v1.end());
			cout<<v1[0]<<endl;
		}
		else cout<<"No second way"<<endl;
		v1.clear();
	}
	
	return 0;
}
