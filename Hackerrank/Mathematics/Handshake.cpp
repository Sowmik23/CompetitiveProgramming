#include <bits/stdc++.h>
using namespace std;

//Print the number of handshakes for each test-case in a new line.

int main()
{
	int t,n;
	scanf("%d",&t);
	
	int res;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		res = 0;
		for(int i=n-1;i>=0;i--){
			res+=i;
		}
		printf("%d\n",res);
	}
	
	
	return 0;
}
