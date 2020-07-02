#include <stdio.h>

int main()
{
double i,j,k;

for(i=0.0;i<=2.0;i+=.2){
j=1.0;
for(k=1.0;k<=3.0;k++){
printf("I=%.1lf J=%.1lf\n",i,j);
j+=0.2;
}
}

return 0;
}
