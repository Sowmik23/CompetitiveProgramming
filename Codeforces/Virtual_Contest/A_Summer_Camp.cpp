#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		str+=to_string(i);
	}
	//cout<<str<<endl;
	cout<<str[n-1]<<endl;
	
	return 0;
}
