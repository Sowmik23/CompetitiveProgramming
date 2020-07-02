#include <bits/stdc++.h>

using namespace std;

/*
struct object{
	int a;
	int b;
} arr[505];

bool flag;
bool comp(object first, object second)
{
	if(first.a < second.a) return true;
	if(first.a > second.a){
		if(first.b !=second.b) return true;
		else {
			flag = true;
			return false;
		}
	}
	
	return false;
}
 */

int main()
{
	long long int t, n;
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&n);
		long long int arr[n+5],brr[n+5];
		
		bool sorted = true;
		
		for(int k=0;k<n;k++)
		{
			scanf("%lld",&arr[k]);
			if(k>=1 and arr[k] < arr[k-1]) sorted = false;
		}
		
		bool haveZero = false, haveOne = false;
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&brr[j]);
			if(brr[j]==0) haveZero = true;
			else if(brr[j]==1) haveOne = true;
		}
		
		if(haveZero==true and haveOne ==true) printf("Yes\n");
		else if(sorted==true) printf("Yes\n");
		else printf("No\n");
		
	}
	
	return 0;
}
