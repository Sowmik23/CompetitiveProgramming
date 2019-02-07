#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a,arr[500000];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	sort(arr,arr+n);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&a);
		int d=lower_bound(arr,arr+n,a)-arr;
		int k=upper_bound(arr,arr+n,a)-arr;
		if(k>=n and d-1<0) printf("X X\n");
		else if(k>=n and d-1>=0) printf("%d X\n",arr[d-1]);
		else if(k<n and d-1<0) printf("X %d\n",arr[k]);
		else printf("%d %d\n",arr[d-1],arr[k]);
	}
	
	return 0;
}
