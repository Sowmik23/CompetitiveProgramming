#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x1,x2,a,b;
	char k1,k2;
	scanf("%c%d",&k1,&x1);
	scanf(" %c%d",&k2,&x2);
	//printf("%c %d %c %d\n",k1,x1,k2,x2);
	a = 'a'-k1;
	b = 'a'-k2;
	int c = abs(a-b);
	int d = abs(x1-x2);
	if(c>=d) printf("%d %d\n",d,c);
	else printf("%d %d\n",c,d);
	
	return 0;
}
