#include <bits/stdc++.h>

using namespace std;

int main()
{
	int r,n;
	int i=1;
	while(1)
	{
		scanf("%d%d",&r,&n);
		if(r==0 and n==0) break;
		
		int x = r/n;
		int y = r%n;
		
		int cnt = 0;
		if(x==1 and y==0) cnt = 0;
		else if (x==1 and y!=0) cnt = 1;
		else if(x>1){
			if(y==0) cnt = x-1;
			else cnt = x;
		}
		printf("Case %d: ",i);
		if(x>26) printf("impossible\n");
		else printf("%d\n",cnt);
		i++;
	}
	
	return 0;
}
