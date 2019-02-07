#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,c,d;
	scanf("%d",&n);
	
	int temp1,temp2,cnt=1;
	
	scanf("%d%d%d%d",&a,&b,&c,&d);
	temp1 = a+b+c+d;
	
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		temp2 = a+b+c+d; 
		if(temp2>temp1) cnt++;
	}
	printf("%d\n",cnt);
		
	
	return 0;
}
