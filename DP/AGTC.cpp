#include <bits/stdc++.h>
using namespace std;

char str1[1005],str2[1005];
int visited[1005][1005];

int dp(int i,int j)
{
	if(i<0) return j+1;
	if(j<0) return i+1;
	
	if(visited[i][j]!=0) return visited[i][j];
	
	if(str1[i] == str2[j])
	{
		visited[i][j] = dp(i-1,j-1);
	}
	else 
	{
		visited[i][j] = min(dp(i-1,j),dp(i,j-1));  //deletion, insertion
		visited[i][j] = min(visited[i][j],dp(i-1,j-1)) + 1; // replace
	}
	
	return visited[i][j];
}

int main()
{
	int l1,l2;
	
	while(cin>>l1>>str1>>l2>>str2)
	{
		memset(visited,0,sizeof(visited));
		cout<<dp(l1-1,l2-1)<<endl;
	}
	
	return 0;
}
