//#include <bits/stdc++.h>

//using namespace std;
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define max(a,b)    (((a) > (b)) ? (a) : (b))


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}


//converting decimal number (x.*****) to mixed fraction (x/y)
void foo(double input)
{
    double integral = std::floor(input);
    double frac = input - integral;

   const long precision = 1000000000; // This is the accuracy.


    int gcd_ = gcd(round(frac * precision), precision);

    int denominator = precision / gcd_;
    int numerator = round(frac * precision) / gcd_;

    //std::cout << integral << " + ";
    //std::cout << numerator << "/" << denominator<< std::endl;
    
    printf("%d/%d\n",numerator,denominator);
}


int main()
{
	int y,w,x;
	
	scanf("%d%d",&y,&w);
	
	int greatest = max(y,w);
	x = 6-greatest+1;
	
	//printf("%d\n",x);
	
	double ans = x/6.0;
	
	//printf("%lf\n",ans);
	
	if(ans==0) printf("0/1\n");
	else if(ans==1) printf("1/1\n");
	else 
	{
		//foo(ans);
		if(x==1) printf("1/6\n");
		else if(x==2) printf("1/3\n");
		else if(x==3) printf("1/2\n");
		else if(x==4) printf("2/3\n");
		else if(x==5) printf("5/6\n");
	}
	
	return 0;
}
