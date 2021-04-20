#include <stdio.h>

int main(){
	
	int n;
	scanf("%d", &n);
	
	int sum=0;
	int x = n;
	while(x>=10){
		sum+=x%10;
		x/=10;
	}
	sum+=x;
	printf("%d\n", sum);
	
	
	return 0;
}
