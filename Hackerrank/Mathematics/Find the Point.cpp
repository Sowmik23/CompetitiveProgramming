#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,px,py,qx,qy, mx, my;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&px,&py,&qx,&qy);
		
		mx = 2*qx - px;
		my = 2*qy - py;
	
		printf("%d %d\n",mx,my);
	}
	
	return 0;
}
