#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	while(getline(cin,str))
	{
		int len = str.size();
		for(int i=0;i<len;i++)
		{
			if(str[i]==' ' or i==len-1)
			{
				if(i==len-1)
				{
					for(int j=i;;j--) 
					{
						if(str[j]==' ' or str[j]=='\0') break;
						cout<<str[j];
					}
				}
				else 
				{
					for(int j=i-1;;j--) 
					{
						if(str[j]==' ' or str[j]=='\0') break;
						cout<<str[j];
					}
					cout<<" ";
				}
			}
		}
		cout<<endl;
	}
	
	return 0;
}
