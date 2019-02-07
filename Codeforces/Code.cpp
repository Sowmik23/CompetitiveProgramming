#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,i;
	cin>>n;
	long long int a;
	cin>>a;
	if(a%2==0) a--;
	cout<<a;
	for(i=1;i<n;i++)
	{
		cin>>a;
		cout<<" ";
		if(a%2==0) a--;
		cout<<a;
	}
	cout<<endl;

	
	return 0;
}
