#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q,len;
	char str[305];
	
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&len);
		scanf("%s",str);
		
		if(len==2)
		{
			if(str[0]>=str[1]) 
			{
				printf("NO\n");
			}
			else 
			{
				printf("YES\n");
				printf("2\n");
				cout<<str[0]<<" "<<str[1]<<endl;
			}
		}
		else 
		{
			printf("YES\n");
			printf("2\n");
			cout<<str[0]<<" ";
			for(int i=1;i<len;i++)
			{
				cout<<str[i];
			}
			cout<<endl;
		}
	}
	
	return 0;
}
