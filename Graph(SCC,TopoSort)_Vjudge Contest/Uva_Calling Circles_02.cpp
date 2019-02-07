#include <bits/stdc++.h>
using namespace std;

map<string,int>mp1;
map<int,string>mp2;

vector<int>v1[1000];
vector<int>v1_reverse[1000];
vector<int>res;
int visited[1000],d[1000],f[1000],t=0;
int n,m;

void dfs_visit(int x)
{
	visited[x]=1;
	int l=v1[x].size();
	for(int i=0;i<l;i++)
	{
		int k=v1[x][i];
		if(visited[k]==0) dfs_visit(k);
	}
	res.push_back(x);
}

void dfs_visit2(int x,int p)
{
	visited[x]=0;
	if(p==0) cout<<", ";
	cout<<mp2[x];
	int l=v1_reverse[x].size();
	for(int i=0;i<l;i++)
	{
		int k=v1_reverse[x][i];
		if(visited[k]==1)
		{
			dfs_visit2(k,0);
			//cout<<", ";
			//cout<<mp2[k];
		}
	}
}

void DFS1()
{
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0) dfs_visit(i);
	}
}

void DFS2()
{
	//memset(visited,0,sizeof(visited));
	int len=res.size();
	for(int i=len-1;i>=0;i--)
	{
		if(visited[res[i]]==1)
		{
			//cout<<mp2[res[i]];
			dfs_visit2(res[i],1);
			cout<<endl;
		}
	}
}

int main()
{
	string s1,s2;
	int cs=1;
	while(cin>>n>>m)
	{
		if(n==0 && m==0) break;
		int index=1;
		for(int i=0;i<=n;i++)
		{
			v1[i].clear();
			v1_reverse[i].clear();
		}
		mp1.clear();
		mp2.clear();
		
		while(m--)
		{
			cin>>s1;
			cin>>s2;
			
			if(!mp1[s1])
			{
				mp1[s1]=index++;
				mp2[index-1]=s1;
				//cout<<index<<endl;
			}
			if(!mp1[s2])
			{
				mp1[s2]=index++;
				mp2[index-1]=s2;
				//cout<<index<<endl;
			}
			int x=mp1[s1];
			int y=mp1[s2];
			//cout<<x<<" "<<y<<endl;
			v1[x].push_back(y);
			v1_reverse[y].push_back(x);
		}
		
		if(cs!=1) cout<<endl;
		cout<<"Calling circles for data set "<<cs++<<":"<<endl;
		DFS1();
		DFS2();	
	
	}
	
	return 0;
}

