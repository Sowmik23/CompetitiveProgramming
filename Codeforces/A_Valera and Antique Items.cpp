#include <bits/stdc++.h>
using namespace std;

int arr[55][55],brr[55];

int main()
{
	int n,v;
	scanf("%d%d",&n,&v);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&brr[i]);
		for(int j=0;j<brr[i];j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int cnt[55],l=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<brr[i];j++)
		{
			if(arr[i][j]<v)
			{
				//cout<<arr[i][j]<<" fdfd ";
				cnt[l++]=i+1;
				break;
			}
		}
	}
	cout<<l<<endl;
	for(int i=0;i<l;i++)
	{
		if(i) cout<<" ";
		cout<<cnt[i];
	}
	
	return 0;
}
