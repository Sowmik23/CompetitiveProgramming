#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		sort(arr,arr+n);
		int ans=0;
		for(int i=n-1-2;i>=0;i-=3) ans+=arr[i];
		printf("%d\n",ans);
	}
	
	return 0;
}
