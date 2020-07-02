#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,q,x,y;
	string s,t;
	cin>>n>>m>>q;
	cin>>s;
	cin>>t;
	int ans=0;
	while(q--)
	{
		cin>>x>>y;
		ans=0;
		int j=0;
		for(int i=x-1;i<=y-1;)
		{
			
			if(s[i]==t[j])
			{
				int l=i;
				for(int k=0;k<m;k++)
				{
					l++;
					cout<<s[l]<<" "<<t[k]<<endl;;
				}
				
			}
			else i++;		
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}
