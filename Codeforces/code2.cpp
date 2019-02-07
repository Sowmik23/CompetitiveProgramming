#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int a[n],b[n];
	y
	for(int i=0;i<n;i++)
	{	
		cin>>a[i];
	}

	for(int i=0;i<n;i++)
	{
		
		int k=i+1;
		 b[j++]=(k-p);
		 d=0;
		 p=k;
	
	}
	int ans=0;
	int q=0;
	for(int i=0;i<n;)
	{
		int mx=-1;
		for(int l=i;l<b[q];l++)
		{
			cout<<b[q]<<endl;
			if(a[l]>mx) 
			{
				mx=a[l];
			}
		}
		ans+=mx;
		i+=b[q];
		q++;
	}
	cout<<ans<<endl;
	
	
	for(int i=0;i<j;i++)
	{
		cout<<b[i];
		if(i<j-1) cout<<" ";
	}
	cout<<endl;
	
	return 0;
}
