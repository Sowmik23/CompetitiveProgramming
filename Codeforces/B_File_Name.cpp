#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string str;
	scanf("%d",&n);
	cin>>str;
	
	int ans=0,cnt=0;
	int c;
	for(int i=0;i<n;)
	{
		if(str[i]=='x')
		{
			cnt=1;
			c=0;
			for(int j=i;j<n;j++)
			{	
				c++;
				if(str[j]=='x' and str[j+1]=='x') cnt++;
				else 
				{
					//cout<<"else"<<cnt<<endl;
					if(cnt>=3) ans+=(cnt-2);
					i+=c;
					break;
				}
			}
		}
		else i++;
	}
	printf("%d\n",ans);
	
	
	return 0;
}

