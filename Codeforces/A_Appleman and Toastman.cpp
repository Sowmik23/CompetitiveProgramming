#include <bits/stdc++.h>
using namespace std;

long long int arr[300009],s[300009];

int main()
{
	long long int n,sum=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		sum+=arr[i];
	}
	sort(arr,arr+n);
	long long int ans =sum,d=0;
	for(int i=0;i<n;i++)
	{
		d += arr[i];
		s[i] = d;
	}
	for(int i=0;i<n-1;i++)
	{
		ans+=(arr[i] + sum-s[i]);
	}
	
	cout<<ans<<endl;
	
	return 0;
}
