#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	string str,str1,str2;
	cin>>t;
	//cin.get();
	while(t--)
	{
		cin.get();
		while(1)
		{
			cin>>str;
			if(str=="*") break;
		}
		while(1)
		{
			//cin>>str1>>str2;
			getline(cin,str1);
			
			
			if(str1[0]=='\0') break;
			int l=str1.size();
			int cnt=0;
			for(int i=0;i<l;i++)
			{
				if(str1[i]!=str2[i]) cnt++;
			}
			cout<<str1<<" "<<str2<<" "<<cnt<<endl;
		}
	}
	
	
	return 0;
}
