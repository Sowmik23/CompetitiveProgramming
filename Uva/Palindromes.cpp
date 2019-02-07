#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	while(1)
	{
		getline(cin,str);
		if(str=="") break;
		
		int len=str.size();
		int mirrored=0,regular=0;
		
		for(int i=0;i<len;i++)
		{
			if(str[i]==str[len-1-i])
			{
				regular++;
			}
		}
		for(int i=0;i<len;i++)
		{
			if((str[i]=='E' && str[len-1-i]=='3') || (str[i]=='3' && str[len-1-i]=='E') || 
			(str[i]=='J' && str[len-1-i]=='L') || (str[i]=='L' && str[len-1-i]=='J') || 
			(str[i]=='S' && str[len-1-i]=='2') || (str[i]=='2' && str[len-1-i]=='S') || 
			(str[i]=='Z' && str[len-1-i]=='5') || (str[i]=='5' && str[len-1-i]=='Z') || 
			(str[i]=='A' && str[len-1-i]=='A') || (str[i]=='H' && str[len-1-i]=='H') ||
			(str[i]=='M' && str[len-1-i]=='M') || (str[i]=='I' && str[len-1-i]=='I') ||  
			(str[i]=='V' && str[len-1-i]=='V') || (str[i]=='U' && str[len-1-i]=='U') || 
			(str[i]=='X' && str[len-1-i]=='X') || (str[i]=='W' && str[len-1-i]=='W') || 
			(str[i]=='T' && str[len-1-i]=='T') || (str[i]=='O' && str[len-1-i]=='O') || 
			(str[i]=='Y' && str[len-1-i]=='Y') || (str[i]=='1' && str[len-1-i]=='1') || 
			(str[i]=='8'))
			{
				mirrored++;
			}
		}
		if(len==regular && len== mirrored) cout<<str<<" -- is a mirrored palindrome."<<endl;
		if(len==mirrored && len!=regular) cout<<str<<" -- is a mirrored string."<<endl;
		if(len==regular && len!=mirrored) cout<<str<<" -- is a regular palindrome."<<endl;		
		if(len!=regular && len!= mirrored) cout<<str<<" -- is not a palindrome."<<endl;
		
		cout<<endl;
	}
	return 0;
}
