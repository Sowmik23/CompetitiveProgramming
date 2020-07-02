#include <bits/stdc++.h>
using namespace std;

long long arr[100001];

int main()
{
	int i,n,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		arr[x]+=x;
	}
	//for(i=0;i<=100000;i++) cout<<arr[i]<<" "<<i<<endl;
	for(i=2;i<=100000;i++)
	{
		arr[i] = max(arr[i-1],arr[i]+arr[i-2]);
	}
	cout<<arr[i-1]<<endl;
	
	return 0;
}
