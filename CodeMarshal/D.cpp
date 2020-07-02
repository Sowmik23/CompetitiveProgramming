#include <bits/stdc++.h>
using namespace std;
string str;

int main()
{
	int t,k;

	cin>>t;
	while(t--)
	{
		int ans;
		cin>>k;
		cin>>str;
		
		int len=str.size();
		ans=len;
		
		//cout<<ans<<endl;
		
		if(k>1)
		{
			for(int i=0;i<len-1;i++)
			{
				if(str[i]!=str[i+1]) ans++;
			}
		}
			//cout<<ans<<endl;
		if(k>2)
		{
			for(int j=2;j<k;j++)
			{
				for(int i=0;i<len-j;i++)
				{
					int l=0,g;
					g=i+j;
					
					for(int v=i;v<(i+g)/2;v++)
					{
						//cout<<str[v]<<" " <<str[g-l]<<" "<<v<<" " <<g-l<<endl;
						
						if(str[v]!=str[g-l])
						{
							ans++;
							break;
						}
						//cout<<ans<<" "<<j<<endl;
						l++;
					}
					
					
				}
			}
			
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}

