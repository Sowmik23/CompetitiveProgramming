#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	string str;
	while(cin>>str)
	{
		if(str=="0") break;
		int len = str.size();
		int j=1,ans=0;
		for(int i=len-1;i>=0;i--)
		{
			int k=str[i] -'0';
			ans+= (k*j)%11;
			j*=10;
			j%=11;
		}
		//cout<<ans<<endl;
		
		if(ans%11==0) cout<<str<<" is a multiple of 11.\n";
		else cout<<str<<" is not a multiple of 11.\n";
	}
	
	return 0;
}
