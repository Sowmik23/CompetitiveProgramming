#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,i,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)cout<<char(i%k+'a');
		cout<<endl;
	}
}
