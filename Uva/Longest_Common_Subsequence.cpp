#include <bits/stdc++.h>
using namespace std;

string str1,str2;
int visited[1009][1009];

int dp(int i,int j)
{
	if(i<0 or j<0) return 0;
	
	if(visited[i][j]!=0) return visited[i][j];
	if(str1[i]==str2[j])
	{
		return visited[i][j] = dp(i-1,j-1) + 1;
	}
	return visited[i][j] = max(dp(i-1,j) , dp(i,j-1));
}

int main()
{
	while(getline(cin,str1))
	{
		getline(cin,str2);
		int l1 = str1.size();
		int l2 = str2.size();
		memset(visited,0,sizeof(visited));
		cout<<dp(l1-1,l2-1)<<endl;
	}
		
	return 0;
}
