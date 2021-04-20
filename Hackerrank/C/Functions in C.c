#include <stdio.h>


int max(int x, int y){
	if(x>y) return x;
	else return y;
}


int max_of_four(int a, int b, int c, int d){
	int x = max(a, b);
	int y = max(c, d);
	
	return max(x, y);
}



int main(){
	
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	
	printf("%d\n", max_of_four(a, b, c, d));
	
	
	return 0;
}
