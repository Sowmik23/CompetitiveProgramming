#include <bits/stdc++.h>
using namespace std;        //Correct Implementatin of AP and Bridge//

vector<int>v1[1005];
vector<pair<int,int> >v2;
int visited[1005],ap[1005],low[1005],d[1005],f[1005],pre[1005],child[1005];
int t;

void dfs_visit(int i)
{
	visited[i]=1;
	t=t+1;
	d[i]=low[i]=t;
	child[i]=0;
	int len=v1[i].size();
	for(int j=0;j<len;j++)
	{
		int k=v1[i][j];
		if(visited[k]==0)
		{
			child[i]++;
			pre[k]=i;
			dfs_visit(k);
			low[i]=min(low[i],low[k]);
		
			/*  Articulation Point    */
			if(pre[i]==-1 && child[i]>1) ap[i]=1; /* that means this an ap  */
			if(pre[i]!=-1 && low[k]>=d[i]) ap[i]=1;   /* that means this an ap  */
			/*  Bridge  */
			if(low[k]>d[i])
			{
				if(i<k) v2.push_back(make_pair(i,k));
				else v2.push_back(make_pair(k,i));
			}
		}
		else if(k!=pre[i]) low[i]=min(low[i],d[k]);
	}
	visited[i]=2;
	t=t+1;
	f[i]=t;
}

void DFS(int n)
{
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			dfs_visit(i);
		}
	}
}
			
int main()
{
	int n,m,u,v;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		v1[u].push_back(v);
		v1[v].push_back(u);
	}
	memset(visited,0,sizeof(visited));
	memset(ap,0,sizeof(ap));
	memset(pre,-1,sizeof(pre));
	
	DFS(n);
	
	//print ap//
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(ap[i]==1) cnt++;
	}
	cout<<"Total ap: "<<cnt<<endl;
	for(int i=0;i<n;i++)
	{
		if(ap[i]==1) cout<<i<<" ";
	}
	cout<<endl;
	
	//Print the bridge//
	int l=v2.size();
	cout<<"Number of Bridge: "<<l<<endl;
	sort(v2.begin(),v2.end());
	for(int i=0;i<l;i++)
	{
		cout<<v2[i].first<<" "<<v2[i].second<<endl;
	}
	
	return 0;
}
