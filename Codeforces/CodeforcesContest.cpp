#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int a[n+10],b[m+10];
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int j=0;j<m;j++)
	{
		cin>>b[j];
	}
	
	int cnt=0,j=0;
	for(int i=0;i<n;)
	{
		if(b[j]>=a[i])
		{
			cnt++;
			j++;
			i++;
		}
		else i++;
	}
	cout<<cnt<<endl;
	
	return 0;
}
