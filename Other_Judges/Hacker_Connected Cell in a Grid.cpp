#include <bits/stdc++.h>
using namespace std;

int b[]={0,0,1,-1,1,1,-1,-1};
int c[]={1,-1,0,0,1,-1,-1,1};
int n,m,cnt;
int a[15][15];

int dfs_visit(int i,int j)
{
	if(i<0 || i==n || j<0 || j==m) return 0;
	if(a[i][j]!=1) return 0;
	a[i][j]=0;
	cnt++;
	for(int l=0;l<8;l++)
	{
		dfs_visit(i+b[l],j+c[l]);
	}
	return cnt;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	int mx=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]==1) 
			{
				cnt=0;
				dfs_visit(i,j);
				if(cnt>mx) mx=cnt;
			}
		}
	}
	cout<<mx<<endl;
	
	return 0;
}
