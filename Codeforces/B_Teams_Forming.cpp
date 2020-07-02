#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n+10];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	
	int ans=0;
	for(int i=0;i<n;i+=2)
	{
		//cout<<i<<endl;
		ans+=arr[i+1]-arr[i];
	}
	cout<<ans<<endl;
	
	
	return 0;
}
