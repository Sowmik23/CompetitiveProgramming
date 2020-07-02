#include <bits/stdc++.h>
using namespace std;

int arr[10009];

int main()
{
	int n,cnt=0;
	int i=0;
	while(scanf("%d",&n)==1)
	{
		arr[i]=n;
		cnt++;
		i++;
		sort(arr,arr+cnt);
		if(cnt%2==0)
		{
			int res = (arr[cnt/2] + arr[(cnt/2)-1])/2;
			cout<<res<<endl;
		}
		else
		{
			cout<<arr[(cnt+1)/2-1]<<endl;
		}
	}
	
	return 0;
}
