#include <bits/stdc++.h>
using namespace std;

vector<int>v1[1005];
map<string,int>mp1;
map<int,string>mp2;
set<string>st;
int visited[1005],pre[1005],d[1005],low[1005],ap[1005];
int t;

void dfs_visit(int i)
{
	visited[i]=1;
	t=t+1;
	d[i]=low[i]=t;
	int child=0;
	int len=v1[i].size();
	for(int j=0;j<len;j++)
	{
		int k=v1[i][j];
		if(visited[k]==0)
		{
			child++;
			pre[k]=i;
			dfs_visit(k);
			low[i]=min(low[i],low[k]);
			if((pre[i]==-1 && child>1) || ( pre[i]!=-1 && low[k]>=d[i]))
			{
				st.insert(mp2[i]);
			}
		}
		else if(k!=low[i])
		{
			low[i]=min(low[i],d[k]);
		}
	}
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
	int n,m,Case=1;
	string str,s1,s2;
	
	while(scanf("%d",&n))
	{
		if(n==0) break;	
		mp1.clear();
		mp2.clear();
		st.clear();
		for(int i=0;i<=n;i++) v1[i].clear();
		memset(visited,0,sizeof(visited));
		memset(pre,-1,sizeof(pre));
		memset(ap,0,sizeof(ap));
		
		for(int i=0;i<n;i++)
		{
			cin>>str;
			mp1[str] = i;
			mp2[i]=str;
		}
		scanf("%d",&m);
		while(m--)
		{
			cin>>s1;
			int x=mp1[s1];
			cin>>s2;
			int y=mp1[s2];
			//cout<<x<<" "<<y<<endl;
			//cout<<mp2[x]<<" "<<mp2[y]<<endl;
			v1[x].push_back(y);
			v1[y].push_back(x);
		}
		
		DFS(n);
		int camera=st.size();
		if(Case!=1) cout<<endl;
		printf("City map #%d: %d camera(s) found\n",Case++,camera);
		set<string>::iterator it;
		for(it=st.begin();it!=st.end();it++)
		{
			cout<<*it<<endl;
		}
	}
	
	return 0;
}
