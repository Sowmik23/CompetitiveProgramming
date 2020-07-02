#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,s,d;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&s,&d);
		
		int x = (s+d)/2;
		int y = s - x;
		if(x<0 or y<0)  printf("impossible\n");
		
		else if(x+y==s and max(x,y)-min(x,y)==d)
		{
			printf("%d %d\n",max(x,y),min(x,y));
		}
		else printf("impossible\n");
	}
	
	return 0;
}
