#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int waste =0;
	int cnt = 0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<=a){
			waste+=arr[i];
			if(waste>b) {
				waste = 0;
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	
	
	return 0;
}
