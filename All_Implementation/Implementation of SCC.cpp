#include <bits/stdc++.h>
using namespace std;
int n,m,cnt,t,visited[105];
vector<int>v1[104],v1_reverse[105];
int f[105],res[105];

void dfs_visit1(int i)
{
	visited[i]=1;
	int l=v1_reverse[i].size();
	for(int ii=0;ii<l;ii++)
	{
		int k=v1_reverse[i][ii];
		if(visited[k]==0) dfs_visit1(k);
	}
	t=t+1;
	f[i]=t;
}

void dfs_visit2(int i)
{
	visited[i]=1;
	int l=v1[i].size();
	for(int ii=0;ii<l;ii++)
	{
		int k=v1[i][ii];
		if(visited[k]==0) dfs_visit1(k);
	}
}

void DFS2()
{
	memset(visited,0,sizeof(visited));
	cnt=0;
	for(int i=n;i>0;i--)
	{
		if(visited[res[i]]==0)
		{
			//parent=res[i];
			dfs_visit2(res[i]);
			cnt++;
		}
	}
}


void DFS1()
{
	memset(visited,0,sizeof(visited));
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			dfs_visit1(i);
		}
		res[f[i]]=i;
	}
}

int main()
{
	int x,y;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&x,&y);
		v1[x].push_back(y);
		v1_reverse[y].push_back(x);
	}
	DFS1();
	DFS2();
	cout<<cnt<<endl;

	return 0;
}

/*
input:
10 12
1 2
2 3
3 1
4 3
4 5
5 6
6 4
7 6
7 8
8 9
9 10
10 7

*/
