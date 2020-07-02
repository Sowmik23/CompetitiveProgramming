#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,c=1;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n],cnt=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i-1])
			{
				if(a[i]-a[i-1]==1) cnt++;
			}
		}
		if(cnt>=1) cout<<"Case "<<c++<<": Yes"<<endl;
		else cout<<"Case "<<c++<<": No"<<endl;
	}
	
	return 0;
}
