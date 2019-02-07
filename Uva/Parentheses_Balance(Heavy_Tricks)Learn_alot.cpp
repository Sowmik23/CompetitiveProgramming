#include <bits/stdc++.h>
using namespace std;

int n;
string str;
stack<char>stk;

bool bracket(char open,char close)
{
	if(open=='(' and close==')') return true;
	else if(open=='[' and close==']') return true;
	else return false;
}

bool check(string str)
{
	int l = str.size();
	for(int i=0;i<l;i++)
	{
		if(str[i]=='(' || str[i]=='[')
		{
			stk.push(str[i]);
		}
		else if(str[i]==')' || str[i]==']')
		{
			if(stk.empty() || !bracket(stk.top(),str[i]))
			{
				return false;
			}
			else stk.pop();
		}
	}
	return stk.empty();
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	scanf("%d",&n);
	cin.ignore();
	while(n--)
	{
		getline(cin,str);

		str.erase(remove(str.begin(),str.end(),' '),str.end());  //this line remove all the space in a string //
		//cout<<str<<endl;

		if(str=="") printf("Yes\n");
		else if(check(str)) printf("Yes\n");
		else printf("No\n");
		while(!stk.empty())
		{
			stk.pop();
		}
	}
	
	return 0;
}
