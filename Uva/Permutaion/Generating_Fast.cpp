#include <bits/stdc++.h>
using namespace std;

bool comp(char a, char b)
{
	if(tolower(a)==tolower(b)) return a<b;
	return tolower(a)<tolower(b);
}

int main()
{
	int t;
	scanf("%d",&t);
	char str[15];
	
	while(t--)
	{
		cin>>str;
		
		int l = strlen(str);
		sort(str,str+l,comp);
		cout<<str<<endl;
		while(next_permutation(str,str+l,comp))
		{
			cout<<str<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}
