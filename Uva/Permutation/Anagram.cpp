#include <bits/stdc++.h>

using namespace std;   //to generate permutation use next_permutation() 
					// function 

bool comp(char a , char b)
{
	if(tolower(a)==tolower(b)) return a<b;
	return tolower(a)<tolower(b);
}

int main()
{
	int t;
	scanf("%d",&t);
	char str[10000];
	
	while(t--)
	{
		cin>>str;
		
		int l= strlen(str);
		sort(str,str+l,comp);
		
		cout<<str<<endl;
		
		while(next_permutation(str,str+l,comp))
		{
			cout<<str<<endl;
		}
	}
	
	return 0;
}
