#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	
	while(getline(cin,str))
	{
		if(str=="") break;
		int len = str.size();
		for(int i=0;i<len;i++)
		{
			if(str[i]=='A' || str[i]=='B' || str[i]=='C') printf("2");
			else if(str[i]=='D' || str[i]=='E' || str[i]=='F') printf("3");
			else if(str[i]=='G' || str[i]=='H' || str[i]=='I') printf("4");
			else if(str[i]=='J' || str[i]=='K' || str[i]=='L') printf("5");
			else if(str[i]=='M' || str[i]=='N' || str[i]=='O') printf("6");
			else if(str[i]=='P' || str[i]=='Q' || str[i]=='R' || str[i]=='S') printf("7");
			else if(str[i]=='T' || str[i]=='U' || str[i]=='V') printf("8");
			else if(str[i]=='W' || str[i]=='X' || str[i]=='Y' || str[i]=='Z') printf("9");
			else if(str[i]>='0' and str[i]<='9') cout<<str[i];
			else cout<<str[i];
		}
		printf("\n");
	}
	
	return 0;
}
