#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,m,a,b,arr[500000],brr[500000],sum=0,res,mx,mn;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		sum+=arr[i];
		brr[i]=sum;
	}
	while(m--)
	{
		scanf("%d%d",&a,&b);
		mn= min(a,b);
		mx=max(a,b);
		
		res = brr[mx-1] - brr[mn-1] + arr[mn-1];
		//cout<<res<<endl;
		if(res%2==0) printf("Sim\n");
		else printf("Nao\n");
	}
		
	return 0;
}


