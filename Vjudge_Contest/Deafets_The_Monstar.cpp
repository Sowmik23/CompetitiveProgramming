#include <bits/stdc++.h>
using namespace std;			/*Very interesting problem & answer*/
unordered_map<int,int>cnt;

void Prime_Factor(int x)
{
	if(x%2==0) cnt[2]++;
	while(x%2==0) x/=2;
	for(int i=3;i*i<=x;i++)
	{
		if(x%i==0) cnt[i]++;
		while(x%i==0) x/=i;		
	}
	if(x>2) cnt[x]++;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		cnt.clear();
		for(int i=0;i<n;i++) 
		{
			cin>>a[i];
			Prime_Factor(a[i]);
		}
		int r=0;
		for(auto & i : cnt)
		{
			cout<<i.second<<endl;
			r+=(i.second + 2)/3;
		}
		cout<<r<<endl;
	}
	//cin.ignore(),cin.get();
	
	return 0;
}
