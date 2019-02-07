#include <bits/stdc++.h>
using namespace std;
int a[]={0,0,-1,1 };
int b[]={-1,1,0,0 };
int n,m,p,q,cnt;
char x;
char str[21][21];

void dfs_visit(int i,int j)
{
	//if(i<0 || j<0 || i==n || j==m) return 0;
	if(j<0) j=m-1;
	if(j>=m) j=0;
	if(i<0 || i>=n) return ;
	if(str[i][j]!=x) return ;
	str[i][j]='*';
	cnt++;
	for(int l=0;l<4;l++)
	{
		dfs_visit(i+a[l],j+b[l]);
	}
	return ;
}

int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>str[i][j];
			}
		}
		cin>>p>>q;
		x=str[p][q];
		dfs_visit(p,q);
		int mx=0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(str[i][j]==x)
				{
					cnt=0;
					dfs_visit(i,j);
					if(cnt>mx) mx=cnt;
				}
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
