#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n+5];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	
	int q;
	scanf("%d",&q);
	sort(arr,arr+n);
	
	while(q--)
	{
		int x;

		scanf("%d",&x);
		int c = upper_bound(arr,arr+n,x)-arr;
		
		cout<<c<<endl;
	}
	
	
	return 0;
}
