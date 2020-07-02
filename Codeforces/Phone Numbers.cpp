#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	char str[109];
	scanf("%s",str);
	int l=strlen(str);
	for(int i=0;i<l;i++)
	{
		if(str[i]=='8') cnt++;
	}
	//cout<<cnt<<endl;
	int x;
	if(n>=11) 
	{
		x=n/11;
		if(cnt>=x) printf("%d\n",x);
		else if(cnt<x and cnt>0) printf("%d\n",cnt);
		else printf("0\n");
	}
	else printf("0\n");
	
	
	return 0;
}
