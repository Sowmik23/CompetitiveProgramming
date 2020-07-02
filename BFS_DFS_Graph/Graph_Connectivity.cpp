#include <bits/stdc++.h>
using namespace std;
int color[3000];
vector<int>v1[10000];
int n;

void dfs_visit(int i)
{
	color[i]=1;
	int len=v1[i].size();
	for(int j=0;j<len;j++)
	{
		if(color[v1[i][j]]==0)
		{
			dfs_visit(v1[i][j]);
		}
	}
}

void DFS(){
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(color[i]==0)
		{
			dfs_visit(i);
			cnt++;
		}
	}	
	printf("%d\n",cnt);	
}

int main()
{
	int t;
	string str,str1;
	scanf("%d\n\n",&t);
	while(t--)
	{
		getline(cin,str);
		n=str[0]-'A' +1;
		while(1)
		{
			getline(cin,str1);
			if(str1[0]==0) break;
			int x = str1[0]-'A'+1;
			int y = str1[1]-'A'+1;
			v1[x].push_back(y);
			v1[y].push_back(x);
		}
		DFS();
		if(t) cout<<endl;
		for(int i=0;i<30;i++)
		{
			color[i]=0;
			v1[i].clear();
		}
	}
	
	return 0;
}
