#include <bits/stdc++.h>
using namespace std;


int n,s,t,c,ans,f;
int res[105][105];
int visited[100000];

void augment(int a,int minEdge)
{
	if(a==s)
	{
		f = minEdge;
		return ;
	}
	else if(visited[a]!=-1)
	{
		augment(visited[a], min(minEdge,res[visited[a]][a]));
		res[visited[a]][a] -=f;
		res[a][visited[a]] +=f;
		return ;
	}
}

int main()
{
	int test=1,x,y,w;;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		scanf("%d%d%d",&s,&t,&c);
		s--,t--;
		
		memset(res,0,sizeof(res));
		
		for(int i=0;i<c;i++)
		{
			scanf("%d%d%d",&x,&y,&w);
			x--,y--;
			res[x][y] +=w;
			res[y][x] +=w;
		}
		ans=0;
		while(1)
		{
			f = 0;
			vector<int> v1(n,INT_MAX);
			v1[s] = 0;
			queue<int>mq;
			mq.push(s);
			memset(visited,-1,sizeof(visited));
			while(!mq.empty())
			{
				int top = mq.front();
				mq.pop();
				if(top==t) break;
				for(int i=0;i<n;i++)
				{
					if(res[top][i]>0 and v1[i]==INT_MAX)
					{
						v1[i] = v1[top] + 1;
						mq.push(i);
						visited[i]= top;
					}
				}
			}
			augment(t,INT_MAX);
			if(f==0) break;
			ans+=f;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",test++,ans);
	}
	
	return 0;
}
