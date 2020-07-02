#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	long long int a[n+5];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int cnt=0,c=1;
	
	for(int i=1;i<n;)
	{
		
		if(a[i-1]<a[i])
		{
			//cout<<c<<" "<<i<<endl;
			int w=n-i;
			cnt+=min(c,w);
			if(min(c,w)==0)i++;
			i+=min(c,w);
			i--;
			c=1;
		}
		else {c++;i++;}
		//cout<<c<<" "<<i<<endl;
	}
	//cout<<c<<" "<<cnt<<endl;
	cout<<cnt<<endl;

	
	return 0;
}
