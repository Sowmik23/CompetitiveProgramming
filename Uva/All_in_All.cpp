#include <bits/stdc++.h>
using namespace std;

int cnt;
string s1,s2;

void dp(int i,int j)
{
	if(i<0 or j<0) return ;

	if(s1[i]==s2[j])
	{
		cnt++;
		dp(i-1,j-1);
	}
	else dp(i,j-1);
}

int main()
{
	while(cin>>s1>>s2 and EOF)
	{
		int l1 = s1.size();
		int l2 = s2.size();
		
		cnt=0;
		dp(l1-1,l2-1);
		if(cnt==l1) printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
