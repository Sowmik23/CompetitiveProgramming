#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,a[111],arr[111]={0};
	set<int>b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) 
	{
		cin>>a[i];
		arr[i]=a[i];
		arr[i]++;
		b.insert(a[i]++);
	}
	set<int>::iterator it;
	
	for(it=b.begin();it!=b.end();it++)
	{
		cout<<*it<<" "<<arr[*it]<<endl;
	}
	
	
	
	return 0;
}

