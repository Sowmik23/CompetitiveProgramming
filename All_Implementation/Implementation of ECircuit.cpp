#include <bits/stdc++.h>
using namespace std;              //0168107787986521// this is a neighbour router's password;
								
									/* This code compiles successfully this is the implementation of Euler Circuit */
set<int>v1[10005];
stack<int>stk;
stack<int>stk2;
int degree[10005];

int isEuler(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(degree[i]%2==1) return 0;
	}
	return 1;
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

		degree[u]++;
		degree[v]++;
	}
	if(isEuler(n)==0)
	{
		printf("There is no euler circuit: -1\n");
		return 0;
	}
	dfs(1);
	while(!stk2.empty())
	{
		cout<<stk2.top()<<" ";
		stk2.pop();
	}
	
	return 0;
}
