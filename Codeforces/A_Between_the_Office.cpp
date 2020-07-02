#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string str;
	scanf("%d",&n);
	cin>>str;
	int cnt=0,cn=0;
	
	for(int i=0;i<n-1;i++)
	{
		if(str[i]=='S' and str[i+1]=='F') cnt++;
		else if(str[i]=='F' and str[i+1]=='S') cn++;
	}
	//cout<<cnt<<" "<<cn<<endl;
	if(cnt>cn) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
