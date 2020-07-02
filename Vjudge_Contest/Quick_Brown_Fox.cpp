#include <bits/stdc++.h>
using namespace std;

map<char,int>mp;

int main()
{
	int n;
	string str;
	
	scanf("%d",&n);
	cin.ignore();
	while(n--)
	{
		//cin.ignore();

		getline(cin,str);
		int len = str.size();
		
		for(int i=0;i<26;i++)
		{
			char x = 'a' + i;
			mp[x]=0;
		}
		
		for(int i=0;i<len;i++)
		{
			str[i] = tolower(str[i]);
			//cout<<str[i]<<endl;
			if(str[i]>='a' and str[i]<='z')
			{
				mp[str[i]]=1;
				//cout<<(char)str[i]<<endl;
			}
		}
		
		int cnt=0;
		string ans="";
		
		for(int i=0;i<26;i++)
		{
			char x = 'a' + i;
			if(mp[x]==0) 
			{
				cnt++;
				ans+=x;
			}
			//cout<<mp[x]<<" "<<x<<endl;
		}
		
		if(cnt==0) printf("pangram\n");
		else 
		{
			printf("missing ");
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
