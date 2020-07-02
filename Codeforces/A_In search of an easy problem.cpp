#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,flag=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x==1)
		{
			printf("HARD\n");
			flag=1;
			break;
		}
	}
	if(flag!=1) printf("EASY\n");
	
	return 0;
}

