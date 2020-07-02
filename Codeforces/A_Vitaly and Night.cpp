#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			if(x==1 or y==1) cnt++;
		}
	}
	printf("%d\n",cnt);
	
	return 0;
}
