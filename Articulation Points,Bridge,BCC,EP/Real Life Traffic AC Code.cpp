
#include<bits/stdc++.h>
using namespace std;

vector<int>ar[100005];
int d[100005],low[100005],visited[100005],par[100005],ans[100005];
vector<int>cn;
set< pair<int,int> >st;
int tim,cnt;

void dfs_visit(int x)
{
    visited[x]=1;tim++;
    d[x]=tim;
    low[x]=d[x];
    int child=0;
    for(int i=0;i<ar[x].size();i++)
    {
        if(visited[ar[x][i]]==0)
        {
            par[ar[x][i]]=x;
            child++;
            dfs_visit(ar[x][i]);
            low[x]=min(low[x],low[ar[x][i]]);
            
            if((low[ar[x][i]] >d[x] ))//&& par[x]!=-1)||(par[x]==-1 && child>1))
            {
                st.insert(make_pair(min(x,ar[x][i]),max(x,ar[x][i])));
            }
        }
        else if(par[x]!=ar[x][i])
        {
            low[x]=min(low[x],d[ar[x][i]]);
        }
    }
}


void DFS(int x)
{
	visited[x]=1;
	d[x]=cnt;
	for(int i=0;i<ar[x].size();i++)
	{
		if(visited[ar[x][i]]==0)
		{
			if(!st.count(make_pair(min(x,ar[x][i]),max(x,ar[x][i]))))
			{
				DFS(ar[x][i]);
			}
		}
	}
}

int main()
{
    int n,m,u,v,tt=0;
    cin>>tt;
    for(int ii=1;ii<=tt;ii++)
    {
		cin>>n>>m;
		tim=0;
		memset(low,100000,sizeof(low));
		memset(par,-1,sizeof(par));
		memset(d,0,sizeof(d));
		memset(visited,0,sizeof(visited));
		while(m--)
		{
			cin>>u>>v;
			ar[u].push_back(v);
			ar[v].push_back(u);
		}
		cout<<"Case "<<ii<<": ";
		cnt=0;
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				dfs_visit(i);
			}
		}
		cnt=0;
		memset(visited,0,sizeof(visited));
		memset(d,0,sizeof(d));
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				cnt++;
				DFS(i);
			}
		}
		
		set< pair<int,int> >:: iterator it;
		for(it=st.begin();it!=st.end();it++)
		{
			ans[d[(*it).first]]++;
			ans[d[(*it).second]]++;
		}
		
		int cnt1=0;
		for(int i=1;i<=cnt;i++)
		{
			if(ans[i]==1)cnt1++;
		}
		//cout<<cnt1<<endl;
		cout<<(cnt1+1)/2<<endl;
		st.clear();
		for(int i=0;i<=n+5;i++) {ar[i].clear();}
		cn.clear();
	}
    return 0;
}
