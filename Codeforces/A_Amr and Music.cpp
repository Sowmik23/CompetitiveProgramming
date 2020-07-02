#include <bits/stdc++.h>
using namespace std;

pair<int,int>arr[109];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int brr[n+10];
	for(int i=0;i<n;i++)
	{
		 scanf("%d",&arr[i].first);
		 arr[i].second=i;
	 }
	
	sort(arr,arr+n);
	int sum=0,cnt=0;
	int j =0;
	for(int i=0;i<n;i++) 
	{
		 sum+=arr[i].first;
		 if(sum<=k)
		 {
			  cnt++;
			  brr[j++]=arr[i].second+1;
		  }
		 else break;
	}
	
	sort(brr,brr+j);
	cout<<j<<endl;
	for(int i=0;i<j;i++)
	{
		if(i) cout<<" ";
		 cout<<brr[i];
	 }
	 cout<<endl;

	return 0;
}

