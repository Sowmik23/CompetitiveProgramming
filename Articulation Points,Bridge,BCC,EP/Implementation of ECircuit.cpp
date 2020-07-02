#include <bits/stdc++.h>
using namespace std;              //0168107787986521// this is a neighbour router's password;
								
									/* This code compiles successfully this is the implementation of Euler Circuit */
vector<int>v1[10005];
stack<int>st;
int degree[10005];

int isEuler(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(degree[i] & 1) return 0;
	}
	return 1;
}

void dfs(int x)
{
	//int len=v1[x].size();   //**don't use this line otherwise u will mara khabe :)  **//
	for(int i=0;i<v1[x].size();i++)
	{
		int t=v1[x].back();
		v1[x].pop_back();
		vector<int>:: iterator it;
		for(it=v1[t].begin();it!=v1[t].end();it++)
		{
			if(*it==x)
			{
				v1[t].erase(it);break;
			}	
		}
		dfs(t);
	}
	st.push(x);
}

int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&u,&v);
		v1[u].push_back(v);

		degree[u]++;
		degree[v]++;
	}
	if(isEuler(n)==0)
	{
		printf("There is no euler circuit: -1\n");
		return 0;
	}
	dfs(1);
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	
	return 0;
}
