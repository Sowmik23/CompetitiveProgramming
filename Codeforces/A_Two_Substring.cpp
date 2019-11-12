#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin>>str;
	
	int len = str.size();
	
	bool res1= false,res2 = false, flag = true;
	
	if(len<=3)
	{
		if(str[0]=='A' and str[1]=='B' and str[2]=='A') res1 = false;
		else if(str[0]=='B' and str[1]=='A' and str[2]=='B') res2 = false;
	}
	else if(len>=4)
	for(int i=0;i<len;)
	{
		if(str[i]=='A')
		{
			if(str[i+1]=='B')
			{
				if(str[i+2]=='A')
				{
					if(str[i+3]!='B')
					{
						flag = false;
						//break;
					}
					res1 = true;
				}
				else res1 = true;
			}
		}
		else if(str[i]=='B')
		{
			if(str[i+1]=='A')
			{
				if(str[i+2]=='B')
				{
					if(str[i+3]!='A')
					{
						flag = false;
						//break;
					}
					res2 = true;
				}
				else res2 = true;
			}
		}
	}
	if(res1==true and res2==true) printf("YES\n");
	
	else printf("NO\n");
	
	return 0;
}
