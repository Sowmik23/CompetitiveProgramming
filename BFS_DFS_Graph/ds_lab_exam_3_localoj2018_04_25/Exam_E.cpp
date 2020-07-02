#include <bits/stdc++.h>
using namespace std;
int cnt,n,m;
int a[]={0,0,1,-1}; 
int b[]={1,-1,0,0};
char str[105][105];

void bfs_visit(int i,int j)
{
	if(i<0 || j<0 || i==n || j==m) return;
	if(str[i][j]!='.') return ;
	
	str[i][j]='#';
	cnt++;
	for(int l=0;l<4;l++)
	{
		bfs_visit(i+a[l],j+b[l]);
	}
}
	
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	int mx=-19;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cnt=0;
			if(str[i][j]=='.') 
			{
				bfs_visit(i,j);
				mx=max(mx,cnt);
			}
		}
	}
	cout<<mx<<endl;
	
	return 0;
}
