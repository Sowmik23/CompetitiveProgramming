#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test ;
	double r;
	scanf("%d",&test);
	for(int i=1;i<=test;i++)
	{
		scanf("%lf",&r);
		printf("Case %d: %.4lf\n",i,r*r/4);
	}
	
	return 0;
}
