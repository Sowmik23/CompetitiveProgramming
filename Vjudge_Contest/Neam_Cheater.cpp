#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,x,y,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ans=a[0];
		if(n>1)
		{
			int i=1;
			while(1)
			{
				if(i>=n) break;
				x=ans;
				y=a[i];
				ans=x^y;
				x=ans;
				i++;
			}
		}
		if(ans==0) cout<<"1"<<endl;
		else  cout<<"0"<<endl;
	}
	
	return 0;
}
