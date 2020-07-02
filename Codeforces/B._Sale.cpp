#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[n+10];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	
	sort(arr,arr+n);
	int sum=0,cnt=0;
	for(int i=0;i<n;i++) 
	{
		if(arr[i]<0)
		{
			 sum-=arr[i];
			 cnt++;
			 if(cnt==m) break;
		 }
	}
	
	cout<<sum<<endl;

	return 0;
}
