#include <bits/stdc++.h>
using namespace std;

int visited[1005][1005];
string str;

int dp(int l,int r)
{
	if(l==r) return 0;
	if(visited[l][r]!=-1) return visited[l][r];
	
	
	if(str[l]!=str[r])
	{
		int x = min(1 + dp(l+1,r), 1 + dp(l,r-1));
		return visited[l][r] = min(x,1 + dp(l+1,r-1));
	}
	return visited[l][r] = dp(l+1,r-1);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;
	scanf("%d",&t);
	
	for(int k=1;k<=t;k++)
	{
		cin>>str;
		int len = str.size();
		
		for(int i=0;i<len;i++)
		{
			for(int j=0;j<len;j++) visited[i][j]=-1;
		}
		
		int ans = dp(0,len-1);
		
		printf("Case %d: %d\n",k,ans);
	}
	
	return 0;
}
