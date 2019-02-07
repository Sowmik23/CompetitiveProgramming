#include <bits/stdc++.h>		/*    DFS/Topological Sort     */
using namespace std;

vector<int> v1[105];
int visited[105],j,top[105];

void DFS(int a)
{
	visited[a]=1;
	int len=v1[a].size();
	for(int i=0;i<len;i++)
	{
		int k=v1[a][i];
		if(visited[k]==0)
		{
			DFS(k);
		}
	}
	top[j--]=a;
}

void Topological_Sort(int n)
{
	memset(visited,0,sizeof(visited));
	j=n-1;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0) 
		{
			DFS(i);
		}
	}
}


int main()
{
	int n,m,u,v;
	
	while(1)
	{
		cin>>n>>m;
		if(n==0 && m==0) break;
		
		for(int i=0;i<n;i++) v1[i].clear();
		while(m--)
		{
			cin>>u>>v;
			v1[--u].push_back(--v);
		}
		
		Topological_Sort(n);
		
		for(int i=0;i<n;i++)
		{
			cout<<++top[i];
			if(i<n-1) cout<<" ";
			else cout<<endl;
		}	
	}
	
	return 0;
}
