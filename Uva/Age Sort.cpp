#include <bits/stdc++.h>
using namespace std;

int arr[2000005];

int main()
{
	int n;
	
	while(scanf("%d",&n))
	{
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+n);
		for(int i=0;i<n;i++)
		{
			if(i) printf(" ");
			printf("%d",arr[i]);
		}
		printf("\n");
	}
	
	return 0;
}
