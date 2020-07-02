#include <bits/stdc++.h>
using namespace std;

int n,k;
long long int visited[110][110][6];

long long int dp(int position,int previous,int flag)
{
	long long int ans =0;
	
	if(position==n) return 1;
	
	if(visited[position][previous][flag]!=-1 ) return visited[position][previous][flag];
	
	for(int i=0;i<k;i++)
	{
		if(i==0)
		{
			if(previous!=0 and flag)  ans+=dp(position+1,0,flag);
		}
		else ans+=dp(position+1,i,1);
	}			

    return visited[position][previous][flag]=ans;
}


int main()
{
	scanf("%d%d",&n,&k);

	memset(visited,-1,sizeof(visited));
	
	cout<<dp(0,0,0)<<endl;
	
	return 0;
}
