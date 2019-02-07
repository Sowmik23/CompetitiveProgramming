#include <bits/stdc++.h>
using namespace std;

int n,arr[109];

int main()
{
	scanf("%d",&n);
	int mx=0;
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int cnt1=0;
			int cnt0=0;
			int t=0;
			for(int k=i;k<=j;k++)
			{
				if(arr[k]==0) cnt0++;
				else cnt1++;
			}
			for(int k=0;k<i;k++) if(arr[k]==1) t++;
			for(int k=j+1;k<n;k++) if(arr[k]==1) t++;
			if(cnt0+t>mx) mx = cnt0+t;
		}
	}
	printf("%d\n",mx);
	
	return 0;
}
