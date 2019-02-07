#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,ans1=0,ans2=0,a,b=0,cnt=0;
	scanf("%lld",&n);
	a = n;
	while(a>0)
	{
		cnt++;
		a/=10;
	}
	cout<<cnt<<endl; //length of input integer
	for(int i=0;i<cnt-1;i++)
	{
		b = b*10 + 9;
		ans1+=9;
	}
	a = n-b;
	cout<<a<<" "<<b<<endl;   //this is the two digit's whose summation =n
	//now sum the digits;
	while(a>0)
	{
		ans2+=a%10;
		a/=10;
	}
	
	cout<<ans1+ans2<<endl;
	
	return 0;
}
