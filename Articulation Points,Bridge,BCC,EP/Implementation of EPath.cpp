#include <bits/stdc++.h>
using namespace std;             
								
									/* This code compiles successfully this is the implementation of Euler path */
vector<int>v1[10005];
stack<int>st;
int degree[10005],start;

int isEuler(int n)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(degree[i] & 1) 
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
		v1[v].push_back(u);
		
		degree[u]++;
		degree[v]++;
	}
	if(isEuler(n)==0)
	{
		printf("There is no euler path: -1\n");
		return 0;
	}
	dfs(start);
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	
	return 0;
}
