#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int n,m,q;
int visited[22][10009];

struct st{
	int x,y;
}arr[22];

int dp(int pos,int mask)
{
	if(mask == (1<<q)-1)
	{
		return visited[pos][mask] = abs(arr[pos].x-arr[0].x) + abs(arr[pos].y - arr[0].y);
	}
	if(visited[pos][mask]!=0) return visited[pos][mask];
	
	int res = INF;
	for(int i=0;i<q;i++)
	{
		if((mask & (1<<i))==0)
		{
			int val = dp(i, mask | (1<<i)) + abs(arr[pos].x-arr[i].x) + abs(arr[pos].y - arr[i].y);
			if(res>val) res = val;
		}
	}
	return visited[pos][mask] = res;
}


int main()
{
	int t;
	scanf("%d",&t);
	//cout<<(1<<t)<<endl;  //mane 2^t er value 
	//cout<<(t | (1<<t))<<endl;  //or kora r plus kora same kotha
	//cout<<(t & (1<<t))<<endl;
	//cout<<(2 & 3)<<endl;
	
	while(t--)
	{
		scanf("%d%d",&n,&m);

		scanf("%d%d",&arr[0].x,&arr[0].y);
		
		scanf("%d",&q);

		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&arr[i].x,&arr[i].y);
		}
		memset(visited,0,sizeof(visited));
	
		printf("The shortest path has length %d\n",dp(0,1));
	}
	
	return 0;
}
