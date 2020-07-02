#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10] = {1,5,10,20,100};
int visited[10][10000];

int dp(int i,int total)
{
	int res1,res2;
	
	if(i>n) return 0;
	
	
	if(visited[i][total]!=-1) return visited[i][total];
	
	
	return visited[i][total] = max(res1,res2);
}

int main()
{
	scanf("%d",&n);
	
	memset(visited,-1,sizeof(visited));
	
	cout<<dp(0,0)<<endl;
	
	return 0;
}

