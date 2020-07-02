#include  <bits/stdc++.h>
using namespace std;

int main()
{
	int n,d,r,arr[100000],brr[100000],sum,ans;
	while(scanf("%d%d%d",&n,&d,&r))
	{
		if(n==0 and d==0 and r==0) break;
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		sort(arr,arr+n);
		for(int i=0;i<n;i++) scanf("%d",&brr[i]);
	    sort(brr,brr+n);
	    ans = 0;
	    for(int i=0;i<n;i++)
	    {
			sum = arr[i] + brr[n-i-1];
			if(sum>d)
			{
				int x = sum-d;
				ans+=x*r;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
