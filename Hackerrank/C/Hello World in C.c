#include <stdio.h>

int main(){
	
	char str[100];
	char ch[] = "Hello, World!";
	
	scanf("%[^\n]", str);
	
	printf("%s\n%s\n", ch, str);
	
	return 0;
}
