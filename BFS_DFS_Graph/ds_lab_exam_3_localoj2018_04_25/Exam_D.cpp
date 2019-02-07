#include <bits/stdc++.h>
using namespace std;					/*Best Example of Map and Pair */
vector<int>v1[10000];
int visited[10000],d[10000],f[10000],t;
map<pair<int,int>,string>mp;

void dfs_visit(int i)
{
	vector<int>::iterator it;
	t=t+1;
	d[i]=t;
	visited[i]=1;
	for(it=v1[i].begin();it!=v1[i].end();it++)
	{
		if(visited[*it]==0)
		{
			visited[*it]=1;
			
			//cout<<i<<" "<<*it<<"(T)"<<endl;
			mp[make_pair(i,*it)]="(T)";
			
			dfs_visit(*it);
		}
		else if(visited[*it]==1)
		{
			//cout<<i<<" "<<*it<<"(B)"<<endl;
			mp[make_pair(i,*it)]="(B)";
		}
		else if(visited[*it]==2)
		{
			if(d[*it]>d[i])
			{
				//cout<<i<<" "<<*it<<"(F)"<<endl;
				mp[make_pair(i,*it)]="(F)";
			}
			else if(d[*it]<d[i]) 
			{
				//cout<<i<<" "<<*it<<"(C)"<<endl;
				mp[make_pair(i,*it)]="(C)";
			}
		}
	}
	visited[i]=2;
	t=t+1;
	f[i]=t;
}

int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		v1[x].push_back(y);
	}
	for(int i=0;i<n;i++)
	{
		sort(v1[i].begin(),v1[i].end());
	}
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0) 
		{
			dfs_visit(i);
		}
	}

	map<pair<int,int>,string>::iterator it;
	
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->first.first<<" "<<it->first.second<<" "<<it->second<<endl;
	
	}

	return 0;
}
