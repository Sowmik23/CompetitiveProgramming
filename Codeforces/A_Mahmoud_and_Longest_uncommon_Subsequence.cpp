#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str1,str2;
	cin>>str1;
	cin>>str2;
	
	int l1=str1.size();
	int l2=str2.size();
	
	if(str1==str2) printf("-1\n");
	else printf("%d\n",max(l1,l2));

    return 0;
}

