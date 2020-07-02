#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,x;
	string str;
	scanf("%d%d%d",&n,&k,&x);
	int arr[n+10];
	
	for(int i=0;i<n;i++)
	{
		cin>>str;
		arr[i] = stoi(str,nullptr,2);
	}
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		//for(int j=i+1;j<n;j++)
		{
			ans+=(arr[i]^arr[i+1]);
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
