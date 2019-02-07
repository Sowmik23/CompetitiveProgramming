#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,cnt=0;
	cin>>n;
	int cn = n;
	for(int i=1;i<=n-1;i++)
	{
		int k=cn-i;
		int d = k/i;
		//cout<<k<<" "<<d<<endl;
		
		if(d*i==k) cnt++;
	}
	cout<<cnt<<endl;
	
	return 0;
}
