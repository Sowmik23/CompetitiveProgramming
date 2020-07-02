#include <bits/stdc++.h>
using namespace std;              /* This code compiles successfully this is the implementation of Euler path */
																
set<int>v1[10005];
stack<int>stk;
stack<int>stk2;
int degree[10005],start;

int isEuler(int n)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(degree[i]%2==1) 
		{
			cnt++;
			start=i;
		}
	}
	if(cnt==2) return 1;
	else return 0;
}

void dfs(int x)
{
	while(1)
	{
		if(v1[x].size()==0)
		{
			stk2.push(x);
			x=stk.top();
			stk.pop();
		}
		else 
		{
			stk.push(x);
			int y=*v1[x].begin();
			v1[x].erase(y);
			v1[y].erase(x);
			x=y;
		}
		if(stk.empty())
		{
			stk2.push(x);
			break;
		}
	}
}

int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		v1[u].insert(v);
		v1[v].insert(u);
		degree[u]++;
		degree[v]++;
	}
	if(isEuler(n)==0)
	{
		printf("There is no euler path: -1\n");
		return 0;
	}
	dfs(start);
	while(!stk2.empty())
	{
		cout<<stk2.top()<<" ";
		stk2.pop();
	}
	
	return 0;
}
