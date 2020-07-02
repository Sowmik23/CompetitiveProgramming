#include <bits/stdc++.h>
using namespace std;

int main()
{
	int len,cnt;
	string str;
	cin>>str;
	len=str.size();
	cnt=1;
	for(int i=1;i<len;i++)
	{
		if(str[i]!=str[i-1])
		{
			cout<<str[i-1]<<cnt;
			cnt=1;
		}
		else cnt++;
	}
	cout<<str[len-1]<<cnt;
	cout<<endl;
	
	return 0;
}
