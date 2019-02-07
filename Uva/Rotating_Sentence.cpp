#include <bits/stdc++.h>
using namespace std;

vector<string>v1[101];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	string str[101];
	int len=0;
	int i=0;
	
	while(getline(cin,str[i]))
	{
		if(str[i]=="") break;
		
		if(str[i].length()>len) len = str[i].length();
		i++;
	}
	
	for(int j=0;j<len;j++)
	{
		for(int k=i-1;k>=0;k--)
		{
			if(str[k].length()>j) cout<<str[k][j];
			else cout<<" ";
		}
		if(j!=len-1) cout<<endl;
	}
	cout<<endl;
	
	
	return 0;
}
