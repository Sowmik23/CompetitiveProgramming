#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		
		int arr[n];
		for(int j=0;j<n;j++) scanf("%d",&arr[j]);
		
		sort(arr,arr+n);
		
		printf("Case %d: %d\n",i+1,arr[n/2]);
		
	}
	
	return 0;
}
