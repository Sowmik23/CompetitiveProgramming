#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int i,t,a,b,n,p,q,j;
	long long int arr[999999];
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		p=min(a,b);
		q=max(a,b);
		n=q-p+1;
		
		for(i=0;i<n;i++) 
		{
			cin>>arr[i];
		}
		int flag=0;
		for(i=p;i<=q;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==arr[j]) break;
				else if(j==n-1 && i!=arr[j])
				{
					flag=1;
					break;
				}
			}
			if(flag==1) break;
		}
		cout<<i<<endl;
	}
	
	return 0;
}
