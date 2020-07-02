#include <bits/stdc++.h>
using namespace std;

int getres(char str[],int l)
{
	int sum;
	string str2 = str;
	while(l>1)
	{
		sum = 0;
		for(int i=0;i<l;i++)
		{
			int d = str2[i]-'0';
			sum+=d;
		}
		str2=to_string(sum);
		l= str2.size();
	}
		
	return sum;
}

int main()
{
	char str[10];
	while(1)
	{
		scanf("%s",str);
		
		int l=strlen(str);
		if(l==1)
		{
			int check = atoi(str);
			if(check==0) return 0;
			printf("%s\n",str);
		}
		else printf("%d\n",getres(str,l));	
	}
	
	return 0;
}
