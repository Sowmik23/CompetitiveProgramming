#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	int arr[20];
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int mx,mn;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		mx = arr[0];
		mn = arr[0];
		
		for(int i=1;i<n;i++)
		{
			mx = max(mx,arr[i]);
			mn = min(mn,arr[i]);
		}
		//cout<<mx<<" "<<mn<<endl;
		
		cout<<2*(mx-mn)<<endl;
	}
	
	return 0;
}
