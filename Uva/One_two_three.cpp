#include <bits/stdc++.h>
using namespace std;

void comp(string str)
{
	int len = str.size();
	string s1,s2;
	s1 = "one";
	s2 = "two";
	int cnt=0,cn=0;
	if(len==3)
	{
		for(int i=0;i<len;i++)
		{
			if(str[i]!=s1[i]) cnt++;
			if(str[i]!=s2[i]) cn++;
		}
		if(cnt<=1) printf("1\n");
		else if(cn<=1) printf("2\n");
	}
	else if(len==5)  printf("3\n");
}

int main()
{
	int t;
	string str;
	
	scanf("%d",&t);
	while(t--)
	{
		cin>>str;
		comp(str);
	}
	
	return 0;
}
