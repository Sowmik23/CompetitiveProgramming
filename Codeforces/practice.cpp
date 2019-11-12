#include <bits/stdc++.h>

using namespace std;


int main()
{
	char str[101];
	scanf("%s",str);
	
	int l = strlen(str);
	for(int i = l-1;i>=0;i--)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		printf("%c",str[i] - 32);
		
		else if(str[i] >= 'A' && str[i] <= 'Z')
		printf("%c",str[i] + 32);
	}
		 
	return 0;
}
