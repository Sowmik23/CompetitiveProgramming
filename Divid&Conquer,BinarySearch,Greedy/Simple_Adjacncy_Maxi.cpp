#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t,p,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&p,&q);
		string str="";
		while(p>=2 and q>=1)
		{
			str+="101";
			p-=2;
			q--;
		}
		if(p==1 and q>=1)
		{
			str = "01" + str;
			p--;
			q--;
		}
		for(int i=0;i<p;i++) str+='1';
		
		//cout<<str<<endl;
		 
		unsigned long long  ans=0,len;
		len = str.size();
		int j=0;
		for(int i=len-1;i>=0;i--)
		{
			if(str[i]=='1') ans+=pow(2,j);
			j++;
		}
		
		cout<<ans<<endl;
	}

	return 0;
}
