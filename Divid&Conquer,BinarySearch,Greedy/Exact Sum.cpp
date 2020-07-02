#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,arr[10009],tk,ans1,ans2;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		scanf("%d",&tk);
		
		sort(arr,arr+n);
		int low=0,high=n-1;
		while(low<high)
		{
			if(arr[low]+arr[high]==tk)
			{
				ans1=arr[low];
				ans2=arr[high];
				low++;
				high--;
			}
			else if(arr[low]+arr[high]<tk)
			{
				low++;
			}
			else high--;
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);

	}		
	
	return 0;
}
