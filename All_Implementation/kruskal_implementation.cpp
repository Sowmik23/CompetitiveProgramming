#include<bits/stdc++.h>
using namespace std;
vector< pair<pair<int,int>,int> >v;
int par[100005];

void initial(int n)
{
	for(int i=0;i<n;i++)
	par[i]=-1;
}

int find(int par[],int x)
{
	if(par[x]==-1) return x;
	return find(par,par[x]);
}

struct st
{
	int a,b,c;
};
bool comp(st x,st y)
{
	return x.c<y.c;
}

int main()
{
	st ar[100005];
	int n,m;
	cin>>n>>m;
	initial(n);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&ar[i].a,&ar[i].b,&ar[i].c);
	}
	sort(ar,ar+m,comp);
	int sum=0;
	for(int i=0;i<m;i++)
	{
		int xx=find(par,ar[i].a);
		int yy=find(par,ar[i].b);
		
		if(xx!=yy)
		{
			par[xx]=yy;
			sum+=ar[i].c;
			v.push_back({{ar[i].a,ar[i].b},ar[i].c});
		}
	}
	cout<<"weight of MST: "<<sum<<endl;
	cout<<"MST edges are: "<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].first.first<<" "<<v[i].first.second<<endl;
	}
}
