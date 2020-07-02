#include <bits/stdc++.h>
using namespace std;

char str[109][109];
int n,m;

int a[] = {1,-1,0,0,-1,1,1,-1 } ;
int b[] = {0,0,1,-1,-1,-1,1,1 } ;

void fun(int i,int j)
{
	if(i<0 or j<0 or i>=n or j>=m) return ;

	if(str[i][j]!='@') return ;
	if(str[i][j]=='@') str[i][j]='*';
	for(int l=0;l<8;l++)
	{
		fun(i+a[l],j+b[l]);
	}
}

int main()
{
	while(scanf("%d%d",&n,&m))
	{
		if(n==0 and m==0) break;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>str[i][j];
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{	
				if(str[i][j]=='@')
				{
					fun(i,j);
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
