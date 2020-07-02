#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string str;
	
	scanf("%d",&n);
	cin.ignore();
	
	while(n--)
	{
		getline(cin,str);
		int len = str.size();
		//cout<<str<<endl;
		
		string simon = "Simon says ";
		//cout<<simon<<endl;
		
		int j=0;
		for(int i=0;i<len;i++)
		{
			if(j<=11)
			{
				if(str[i]==simon[j])
				{
					j++;
					continue;
				}
			}
			//cout<<j<<endl;
			if(j==11)
			{
				cout<<str[i];
			}
			else break;
		}
		cout<<endl;
	}
	
	return 0;
}
