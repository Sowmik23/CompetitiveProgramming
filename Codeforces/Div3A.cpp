#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	int a[m+5];
	for(int i=1;i<=m;i++)
	{
		a[i]=0;
	}
	
	while(n--)
	{
		scanf("%d%d",&x,&y);
		for(int i=x;i<=y;i++)  if(a[i]==0) a[i]=1;		
	}
	int b[m+5];
	int j=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i]==0) 
		{
			b[j++]=i;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++) 
	{
		if(i) cout<<" ";
		cout<<b[i];
	}
	cout<<endl;	
	
	
	return 0;
}
