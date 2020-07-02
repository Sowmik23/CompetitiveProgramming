#include <bits/stdc++.h>
using namespace std;


int main()
{
	long long int a,b,x,y;
	scanf("%lld%lld",&a,&b);
	long long int cnt=0;
	x = a;
	y = b;
	if(y==1 ) cout<<x<<endl;
	else if(abs(x-y)==1) cout<<max(x,y)<<endl;
	else 
	{
		while(1)
		{
			if(x>y)
			{	
				cnt+=x/y;
				x%=y;
			}
			else 
			{
				cnt+=y/x;
				y%=x;
			}
			if(x==0 or y==0) break;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
