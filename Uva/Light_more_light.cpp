#include <bits/stdc++.h>
using namespace std;

/* One way to go about it is to check all the values i 
 * below n and flip a flag if n is divisible by i. This approach
 *  will TLE. The correct approach to make the observation 
 * that numbers that are not perfect squares have an even number
 *  of factors. Perfect squares have an odd number of factors.
 *  For example, 4 has factors 1 2 and 4 (odd). 12 has 
 * factors 1 2 3 4 6 12 (even). Therefore if n is a perfect square, 
 * output “yes”. Otherwise output “no”.
 * */
int main()
{
	long long int n;
	while(scanf("%lld",&n))
	{
		if(n==0) break;
		long long int x = sqrt(n);
		
		if(x*x==n) printf("yes\n");
		else printf("no\n");
	}
	
	return 0;
}
