#include <stdio.h>
#include <math.h>

//description: Given two integers, n and m, how many digits have n^m?

int main()

{
    int i,t,count=0,number,n,m;

    scanf("%d",&t);

    for(i=0; i<t; i++)
    {
        count = 0;
        scanf("%d%d",&n,&m);

        //number=pow(n,m);
        
        //printf("%lld\n",number);
        
        double lg, cnt;
        lg = log10(n);
        printf("lg : %lf\n",lg);
        cnt = double (lg*m);  //type casting 
        printf("%lf\n",cnt);
        
        count = floor(cnt) + 1;
        printf("%d\n",count);  //final result
       
    }

    return 0;
}
