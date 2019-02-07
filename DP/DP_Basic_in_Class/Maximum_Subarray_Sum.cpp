#include <bits/stdc++.h>
using namespace std;

int dp(int arr[],int n)
{
	int res=0,ans=0;
	for(int i=0;i<n;i++)
	{
		res = max(arr[i],res+arr[i]);
		ans = max(ans,res);
	}
	return ans;
}

int main()
{
	int n,arr[1000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("%d\n",dp(arr,n));
	
	return 0;
}
/*
Input: 
6
3 -4 9 -8 8 7
Output: 
16
* */


