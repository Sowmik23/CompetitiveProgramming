#include <bits/stdc++.h>
using namespace std;

struct st{
	double ratio;
	int pos;
}arr[50000];

bool comp(st x,st y)
{
	return x.ratio>y.ratio;
}

int main()
{
	int t,n,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			arr[i].ratio = double (b)/a;
			arr[i].pos = i+1;
		}
		sort(arr,arr+n,comp);
		
		//for(int i=0;i<n;i++) cout<<arr[i].ratio<<" "<<arr[i].pos<<endl;
		for(int i=0;i<n;i++) 
		{
			if(i) printf(" ");
			printf("%d",arr[i].pos);
		}
		printf("\n");
		if(t) printf("\n");
	}
	
	return 0;
}
