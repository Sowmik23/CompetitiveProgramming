#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,m,a,b,sum=0,d;
	
	cin>>n>>m;
	long long int arr[110910];
	int i=0;
	d=n;
	while(d--)
	{
		cin>>a>>b;
		arr[i]=(a-b);
		sum+=a;
		i++;
	}

	sort(arr,arr+n);
	if(sum<=m) cout<<0<<endl;
	else if(sum>m)
	{
		int cnt=0;
		for(int j=n-1;j>=0;j--)
		{
			sum-=arr[j];
			cnt++;
			if(sum<=m) 
			{
				cout<<cnt<<endl;
				return 0;
			}
		}
		cout<<-1<<endl;
	}
	else 
	cout<<"-1"<<endl;
	
	return 0;
}
