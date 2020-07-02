#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int p,long long int d)
{
	if(d==0) return p;
	return gcd(d,p%d);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int len=str.length();
		int cnt=0,flag=0;
		for(int i=len-1;i>=0;i--)
		{
			if(str[i]=='.' ) 
			{
				flag=1;
				break;
			}
			cnt++;
		}
		if(flag==0) cnt=0;
		//cout<<cnt<<endl;
		int num=0;
		for(int i=0;i<len;i++)
		{
			if(str[i]!='.') 
			{
				num=num*10 + (str[i]-'0');
			}
		}
		//cout<<num<<endl;
		int l=pow(10,cnt);
		int k=gcd(num,l);
		cout<<l/k<<endl;
		
	}	
	
	return 0;
}

