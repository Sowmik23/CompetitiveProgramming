#include <bits/stdc++.h>

using namespace std;

int main()
{
	double a,b,c;
	scanf("%lf%lf%lf",&a,&b,&c);
	
	double greatest = a;
	
	if(a<=b || a<=c) {
		if(b>=c){
			greatest = b;
		}
		else {
			greatest = c;
		}
	}
	
	printf("%lf\n",greatest);
		
	
	
	
	return 0;
}
