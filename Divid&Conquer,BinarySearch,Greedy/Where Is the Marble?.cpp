#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a,arr[500000];
	for(int i=1;;i++)
	{
		scanf("%d%d",&n,&m);
		if(n==0 and m==0) break;
		
		for(int k=1;k<=n;k++) arr[k]=0;
		
		int j=0;
		while(n--)
		{
			scanf("%d",&a);
			arr[j]=a;
			j++;
		}
		sort(arr,arr+j);
		printf("CASE# %d:\n",i);
		while(m--)
		{
			scanf("%d",&a);
			int ans = lower_bound(arr,arr+j,a)-arr;  //to determine lower bound of a//
			if(arr[ans]==a) printf("%d found at %d\n",a,ans+1);
			else printf("%d not found\n",a);
		}
	}
	
	return 0;
}
