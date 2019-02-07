#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	while(1)
	{
		scanf("%lld",&n);   //Number of straight line to cut pizza
		if(n<0) break;
		long long int total_pieces = (n*(n+1)/2) + 1;
	    
	    printf("%lld\n",total_pieces);   //maximum number of pieces
	}
	
	return 0;
}
