#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[110];
		cin>>(str+1);
		int len=strlen(str+1);
		int a=0, b=0,c=0;
		
		for(int i=1;i<=len;i++)
		{
			if(str[i]>='0' and str[i]<='9') a=i;
			if(str[i]>='a' and str[i]<='z') b=i;
			if(str[i]>='A' and str[i]<='Z') c=i;
		}
		
		if(a==0)
		{
			for(int i=1;i<=len;i++)
			{
				if(i!=b and i!=c)
				{
					a=i;
					str[i]='1';
					break;
				}
				
			}	
		}
		if(b==0)
		{
			for(int i=1;i<=len;i++)
			{
				if(i!=a and i!=c)
				{
					b=i;
					str[i]='a';
					break;
				}
				
			}	
		}
		if(c==0)
		{
			for(int i=1;i<=len;i++)
			{
				if(i!=a and i!=b)
				{
					c=i;
					str[i]='A';
					break;
				}
				
			}	
		}
		cout<<str+1<<endl;
	}
		
	return 0;
}
