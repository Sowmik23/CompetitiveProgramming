#include <bits/stdc++.h>
using namespace std;

vector<int> v1[50];
int visited[201][21];

int dp(int m,int c)
{
	if(m<0) return -2;   //negative money means no solution
	if(c==0) return 0;   //no more garment to buy, so this is a solution
	
	if(visited[m][c]!=-1) return visited[m][c];
	
	visited[m][c] = -2;     	//initialize the state having no solution
	for(int i=0;i<v1[c-1].size();i++)  //for all model of this garment
	{
		int ci = v1[c-1][i];     //the price of model ci of garment c-1
		if(dp(m-ci,c-1)!=-2)    //if this model can produce a solution
		{
			visited[m][c] = max(visited[m][c] , dp(m-ci,c-1) + ci);  //update the maximum money spent
		}
	}
	return visited[m][c];
}

int main()
{
	int t,m,c,k;
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&c);
		for(int i=0;i<c;i++)
		{
			scanf("%d",&k);
			
			v1[i].resize(k);   //resize the vector to size k
			
			for(int j=0;j<k;j++)
			{
				scanf("%d",&v1[i][j]);
			}
		}
		memset(visited,-1,sizeof(visited));
		if(dp(m,c)==-2) printf("no solution\n");
		else printf("%d\n",dp(m,c));
	}
	
	return 0;
}
