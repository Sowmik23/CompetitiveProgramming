#include <bits/stdc++.h>
/*
#include <stack>
#include <stdlib.h>
#include <string.h>*/
using namespace std;

bool Bracket(char open,char close)
{
    if(open=='(' && close ==')') return true;
    else if(open=='{' && close =='}') return true;
    else if(open=='[' && close ==']') return true;
    else return false;
}

bool ParenthesesBalanced(string b)
{
    int i,l;
    stack<char>a;
    for(i=0;i<b.length();i++)
    {
        if(b[i]=='(' || b[i]=='{' || b[i]=='[') a.push(b[i]);
        
        else if(b[i]==')' || b[i]=='}' || b[i]==']')
        {
            if(a.empty() || !Bracket(a.top(),b[i])) return false;
            else a.pop();
        }
    }
    return a.empty();
}

int main() {
	string c;
	cin>>c;
	cout<<c<<endl;
	if(ParenthesesBalanced(c))
	{
	    cout<<"Yeah!!!"<<endl;
	}
	else cout<<"Sorry!!!NOt Balanced."<<endl;
	
	return 0;
}