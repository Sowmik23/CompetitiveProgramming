#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k,sum=0;
	scanf("%d%d",&n,&m);
	int a[n+10],b[n+m+1000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	k=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i-1];j++)
		{
			b[k++]=i;
		}
	}
	for(int i=0;i<k;i++) cout<<b[i]<<" ";
	
	
	
	
	return 0;
}
