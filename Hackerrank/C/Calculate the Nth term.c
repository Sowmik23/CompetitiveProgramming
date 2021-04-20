#include <stdio.h>


int nthTerm(int n, int a, int b, int c){
	if(n==1) return a;
	else if(n==2) return b;
	else if(n==3) return c;
	
	return nthTerm(n-1, b, c, a+b+c);
}

int main(){
	
	int n, a, b, c;
	
	scanf("%d", &n);
	scanf("%d%d%d", &a, &b, &c);
	
	printf("%d\n", nthTerm(n, a, b, c));
	
	
	return 0;
}

