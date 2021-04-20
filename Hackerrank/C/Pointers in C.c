#include <stdio.h>
#include <math.h>


void update(int *a, int *b){
	(*a)+=(*b);
	(*b) = abs((*a-*b) - *b);
}


int main(){
	
	int a, b;
	scanf("%d%d", &a, &b);
	
	int *pa = &a;
	int *pb = &b;
	
	update(pa, pb);
	
	printf("%d\n%d\n", a, b);
	
	
	return 0;
}
