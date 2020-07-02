#include <stdio.h>

int main()
{
	double greatest,greatest2,greatest3,a,b,c,x,y,z;
	int check;
	scanf("%lf%lf%lf",&a,&b,&c);

	greatest=a;
	check=1;
	if(a<b || a<c){
	if(b>c){
	greatest=b;
	check=2;
	}
	else{
	greatest=c;
	check=3;
	}
	}

	if(check==1){
	if(b>c){
	greatest2=b;
	greatest3=c;
	}
	else{
	greatest2=c;
	greatest3=b;
	}
	}

	else if(check==2){
	if(a>c){
	greatest2=a;
	greatest3=c;
	}
	else{
	greatest2=c;
	greatest3=a;
	}
	}
	else{
	if(a>b){
	greatest2=a;
	greatest3=b;
	}
	else{
	greatest2=b;
	greatest3=a;
	}
	}
	//printf("%lf %lf %lf",greatest,greatest2,greatest3);

	a=greatest;
	b=greatest2;
	c=greatest3;

	x=a*a;
	y=b*b;
	z=c*c;

	if(a>=(b+c)){
	printf("NAO FORMA TRIANGULO\n");
	}
	else {
	if(x==(y+z)){
	printf("TRIANGULO RETANGULO\n");
	}
	if(x>(y+z)){
	printf("TRIANGULO OBTUSANGULO\n");
	}
	if(x<(y+z)){
	printf("TRIANGULO ACUTANGULO\n");
	}
	if(a==b && a==c && b==c){
	printf("TRIANGULO EQUILATERO\n");
	}
	else if((a==b && (a!=c && b!=c)) || (b==c && (b!=a && c!=a)) || (a==c && (a!=b && c!=b))){
	printf("TRIANGULO ISOSCELES\n");
	}
	}
return 0;
}
