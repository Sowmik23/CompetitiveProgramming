#include <bits/stdc++.h>
using namespace std;
char str[101][101];
int n;
int a[] = {0,0,-1,1};//,-1,-1,1,1};
int b[] = {-1,1,0,0};//,-1,1,-1,1};

void dfs_visit(int i,int j)
{
	if(i<0 || j<0 || i==n || j==n || str[i][j]=='.') return;
	
	if(str[i][j]=='.') return ;
	str[i][j]='.';
	for(int k=0;k<4;k++)
	{
		dfs_visit(i + a[k],j + b[k]);
	}
	return;
}

int main()
{
	int t,l=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			//for(int j=0;j<n;j++)
			{
				cin>>str[i];
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(str[i][j]=='x')
				{
					dfs_visit(i,j);
					cnt++;
				}
			}
		}
		cout<<"Case "<<l++<<": "<<cnt<<endl;
	}
		
	return 0;
}
