#include<bits/stdc++.h>
using namespace std;
pair<int,int> pa;
set< pair<int,int> >ar[100005];
set< pair<int,int> >sttt;
vector<int>stk;
set<int>stt[1005];
stack<int>stkk;
map< pair<int,int>,int>mp;
int deg[1005];

int isEular()
{
	for(int i=0;i<=50;i++)
	{
		if(deg[i]%2==1) return 1;
	}
	return 0;
}

void dfs(int x)
{
	while(1)
	{
		if(ar[x].size()==0)
		{
			stk.push_back(x);
			x=stkk.top();
			stkk.pop();
		}
		else 
		{
			stkk.push(x);
			pa=*ar[x].begin();
			int w=pa.first;
			int y=pa.second;
			ar[x].erase({w,y});
			ar[y].erase({w,x});
			x=y;
		}
		if(stkk.empty())
		{
			stk.push_back(x);
			break;
		}
	}
}

int main()
{
	int u,v,w,cnt,start;
	while(1)
	{
		cin>>u>>v;
		if(u==0 && v==0) break;
		cnt=1;
		start=min(u,v);
		cin>>w;
		ar[u].insert({w,v});
		ar[v].insert({w,u});
		mp[{min(u,v),max(u,v)}]=cnt;
		stt[cnt].insert(w);
		cnt++;
		deg[u]++;deg[v]++;
		while(1)
		{
			cin>>u>>v;
			if(u==0 && v==0) break;
			cin>>w;
			deg[u]++;deg[v]++;
			ar[u].insert({w,v});
			ar[v].insert({w,u});
			if(mp[{min(u,v),max(u,v)}]==0)
			{
				mp[{min(u,v),max(u,v)}]=cnt;
				stt[cnt].insert(w);
				cnt++;
			}
			else stt[mp[{min(u,v),max(u,v)}]].insert(w);
		}
		if(isEular())
		{
			cout<<"Round trip does not exist."<<endl<<endl;
		}
		else 
		{
			dfs(start);
			for(int ii=stk.size()-1;ii>0;ii--)
			{
				pa={min(stk[ii],stk[ii-1]),max(stk[ii],stk[ii-1])};
				int val=mp[pa];
				if(ii!=stk.size()-1) cout<<" ";
				cout<<*stt[val].begin();
				stt[val].erase(stt[val].begin());
			}
			cout<<endl<<endl;
		}
		
		
		for(int i=0;i<100;i++)
		{
			ar[i].clear();stt[i].clear();deg[i]=0;
		}
		stk.clear();
		mp.clear();
		sttt.clear();
	}
	
	return 0;
}
