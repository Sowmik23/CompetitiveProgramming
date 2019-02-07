#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

map<string,int>mp;

double AdjMatrix[108][108];

void initialize(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) AdjMatrix[i][j]=0;
			else AdjMatrix[i][j]=-INF;
		}
	}
}

int main()
{
	int n,m;
	for(int test=1;;test++)
	{
		scanf("%d",&n);
		if(n==0) break;
		initialize(n);
		string str;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			mp[str]=i;
		}
		scanf("%d",&m);
		string str1,str2;
		double c;
		for(int i=0;i<m;i++)
		{
			cin>>str1;
			cin>>c;
			cin>>str2;
			int x=mp[str1];
			int y=mp[str2];
			AdjMatrix[x][y] = c;
		}
		for(int k=0;k<n;k++)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					AdjMatrix[i][j] = max(AdjMatrix[i][j],(AdjMatrix[i][k] * AdjMatrix[k][j]));
				}
			}
		}
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(AdjMatrix[i][i]>1.0)
			{
				flag=1;
				break;
			}
		}
		cout<<"Case "<<test;
		if(flag==1) cout<<": Yes";
		else cout<<": No";
		cout<<endl;
		mp.clear();
	}
	
	return 0;
}
