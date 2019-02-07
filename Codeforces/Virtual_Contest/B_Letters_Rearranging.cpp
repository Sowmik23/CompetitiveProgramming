#include <bits/stdc++.h>
using namespace std;

int palindrome(string s,int l)
{
	for(int i=0;i<=l/2;i++)
	{
		if(s[i]!=s[l-i-1]) return 0;
	}
	return 1;
}

int main()
{
	int n;
	string str;
	scanf("%d",&n);
	while(n--)
	{
		cin>>str;
		int l=str.size();
		if(palindrome(str,l)==1)
		{
			string ss=str;
			sort(ss.begin(),ss.end());
			//cout<<str<<endl;
			if(ss[0]==ss[l-1]) 
			{
				printf("-1\n");
			}
			else cout<<ss<<endl;
		}
		else 
		{
			cout<<str<<endl;
		}
	}
	
	
	return 0;
}
