#include <bits/stdc++.h>
using namespace std;
char str[105][105];
int visited[101][101];
int a[]={0,0,1,-1,-1,-1,1,1};
int b[]={1,-1,0,0,-1,1,-1,1};
int n,m;

void dfs_visit(int i,int j)
{
	if(i<0 || i==n || j<0 || j==m) return ;
	if(str[i][j]=='.')
	{
		visited[i][j]=visited[i][j] +1;
		return ;
	}
	if(str[i][j]!='*') return ;
	str[i][j]='A';
	for(int l=0;l<8;l++)
	{
		dfs_visit(i+a[l],j+b[l]);
	}	
}

int main()
{
	int t=1;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(n==0 && m==0) break;
		if(t>1) cout<<endl;
		
		for(int i=0;i<n;i++)
		{
			cin>>str[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(str[i][j]=='*') visited[i][j]=-1;
				else visited[i][j]=0;
			}
		}		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(str[i][j]=='*') dfs_visit(i,j);
			}
		}
		cout<<"Field #"<<t++<<":"<<endl;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(visited[i][j]==-1) cout<<"*";
				else cout<<visited[i][j];
			}
			cout<<endl;
		}	
	}
	
	return 0;
}
