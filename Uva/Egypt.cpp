#include <bits/stdc++.h>
using namespace std;

int median(int x,int y,int z)
{
	if((x<=y and x>=z) or (x>=y and x<=z)) return x; 
	else if((y<=x and y>=z) or (x<=y and y<=z)) return y; 
	else if((z>=x and z<=y) or (z<=x and z>=y)) return z; 
}

int main()
{
	int a,b,c,x,y,z;
	while(scanf("%d%d%d",&x,&y,&z)==3)
	{
		if(x==0 and y==0 and z==0) break;
		
		a = max(x,y);
		a = max(a,z);
		b = min(x,y);
		b = min(b,z);
		c = median(x,y,z);
		//cout<<a<<" "<<b<<" "<<c<<endl;
		long long d=a*a;
		long long k = c*c;
		long long m = b*b;
		//cout<<d+k<<" "<<m<<endl;
		if(d==k+m) printf("right\n");
		else printf("wrong\n"); 
	}
	
	return 0;
}
