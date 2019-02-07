#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int j,test,len;
	scanf("%lld",&test);
	string str;
	for(long long int ii=1;ii<=test;ii++)
	{
		cin>>str;
		len=str.size();
		printf("Case %lld: ",ii);
		cout<<str;
		for(j=len-2;j>=0;j--)
		{
			cout<<str[j];
		}
		
		cout<<endl;
	}
	
	return 0;
}
