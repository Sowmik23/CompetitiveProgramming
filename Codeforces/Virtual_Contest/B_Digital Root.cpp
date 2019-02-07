#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long q,k,x;
	scanf("%lld",&q);
	string str1,str2,str;
	
	while(q--)
	{
		scanf("%lld %lld",&k,&x);
		
		cout<<(x+(9*(k-1)))<<endl;
	
	}
	
	return 0;
}
