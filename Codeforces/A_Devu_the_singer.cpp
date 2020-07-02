#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	int sum=0,x;
	
	for(int i=0;i<n;i++) 
	{
		scanf("%d",&x);
		sum+=x;
	}
	int k=(n-1)*10;
	if(k+sum>d) cout<<"-1"<<endl;
	else 
	{
		d-=sum;
		cout<<d/5<<endl;
	}
	
	return 0;
}
