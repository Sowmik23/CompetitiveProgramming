#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	int len;
	cin>>str;
	len=str.size();
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='1') cnt++;
	}
	int p,k=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='0') cout<<"0";
		if(str[i]=='2') 
		{
			p=i;
			k=1;
			break;
		}
	}
	for(int i=0;i<cnt;i++) cout<<"1";
	if(k==1)
	{
		for(int j=p;j<len;j++)
		{
			if(str[j]!='1') cout<<str[j];
		}
	}
	cout<<endl;
	
	return 0;
}
