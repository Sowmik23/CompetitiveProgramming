#include <bits/stdc++.h>
using namespace std;

int main () {

    int t,c=1;
    cin>>t;
    cin.get();
    string str;
    while(t--)
    {
		getline(cin,str);
		int len=str.size();
		for(int i=0;i<len;i++)
		{
			if(str[i]>='a' && str[i]<='z') str[i]=toupper(str[i]);
		}
		
		
		cout<<"Case "<<c++<<": "<<str<<endl;
	}

    return 0;
}

