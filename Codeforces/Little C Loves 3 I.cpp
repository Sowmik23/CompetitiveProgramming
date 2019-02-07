#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,c;
	scanf("%d",&n);
	a = 1;
	b = 1;
	c = n-(a+b);
	if(c%3==0) c--,a++;
	cout<<a<<" "<<b<<" "<<c<<endl;
	
	return 0;
}
