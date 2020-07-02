#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d\n",&n);
	string str,s;

	while(n--)
	{
		getline(cin,str);
		stringstream st(str);
		int cnt=0;
		while(st>>s)
		{
			cnt++;
			if(cnt!=1) cout<<" ";
			int len=s.length();
			if(len==1 and cnt==1) printf("%c",toupper(s[0]));
			else 
			{
				for(int i=1;i<len;i++) 
				{
					if(cnt==1 and i==1) printf("%c",toupper(s[1]));
					else cout<<s[i];
				}
				printf("%c",tolower(s[0]));
			}
			cout<<"ay";
		}
		cout<<endl;
	}
	
	return 0;
}


