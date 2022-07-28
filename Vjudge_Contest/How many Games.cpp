#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int p,long long int d)
{
	if(d==0) return p;
	return gcd(d,p%d);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		double x;
		cin>>x;
		double y=x;
		
		long long int d=1,cnt=0;
		while(y!=((long long int)y))
		{
			cnt++;
			d*=10;
			y=y*10;
		}
		//cout<<d<<" "<<cnt<<endl;
		long long int p=d*x;
		
		long long int k = gcd(p,d);
		
		//cout<<k<<endl;
		cout<<d/k<<endl;
	
	}	
	
	return 0;
}
