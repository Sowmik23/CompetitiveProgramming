#include <bits/stdc++.h>
using namespace std;

bool comp(char a, char b)
{
	if(tolower(a)==tolower(b)) return a<b;
	return tolower(a)<tolower(b);
}

int main()
{
	int t, cnt;
	scanf("%d",&t);
	char str[15];
	
	while(t--)
	{
		cnt=0;
		cin>>str;
		
		int l = strlen(str);
		sort(str,str+l,comp);
		cout<<str<<endl;
		while(next_permutation(str,str+l,comp))
		{
			cnt++;
			cout<<str<<endl;
		}
		cout<<endl;
		printf("Total result : %d\n",cnt);
	}
	
	return 0;
}
