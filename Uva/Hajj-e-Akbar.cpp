#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cnt=1;
	string str;
	while(cin>>str)
	{
		if(str=="*") break;
		cout<<"Case "<<cnt<<": ";
		if(str=="Hajj") cout<<"Hajj-e-Akbar"<<endl; 
		else if(str=="Umrah") cout<<"Hajj-e-Asghar"<<endl;
		cnt++;
	}
	
	return 0;
}
