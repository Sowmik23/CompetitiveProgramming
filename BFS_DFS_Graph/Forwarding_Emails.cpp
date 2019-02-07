#include <bits/stdc++.h>
using namespace std;
vector<int>v1[60000];
int visited[60000],length[60000];

int dfs_visit(int a)
{
	vector<int>::iterator it;
	visited[a]=1;
	int d=0;
	for(it=v1[a].begin();it!=v1[a].end();it++)
	{
		if(visited[*it]==0)
		{
			//visited[*it]=1;
			d+=dfs_visit(*it) +1;
		}
	}
	visited[a]=0;
	length[a]=d;
	return length[a];
}



int main()
{
	int t,j=1;
	cin>>t;
	while(t--)
	{
		int n,u,v;
		cin>>n;
		memset(visited,0,sizeof(visited));
		memset(length,0,sizeof(length));
		int m=n;
		while(m--)
		{
			cin>>u>>v;
			v1[u].push_back(v);
		}
		int mx=-1000,x;
		for(int i=1;i<=n;i++)
		{
			if(length[i]==0)
			{
				dfs_visit(i);
			}
			if(length[i]>mx)
			{
				mx=length[i];
				x=i;
			}
		}
		cout<<"Case "<<j++<<": "<<x<<endl;
		for(int i=1;i<=n;i++)v1[i].clear();
	}
	
	return 0;
}
