#include <stdio.h>

int main(){
	
	char ch, cha[100], str[100];
	
	scanf("%c", &ch);
	getchar();
	scanf("%s", cha);
	getchar();
	scanf("%[^\n]", str);
	
	printf("%c\n",ch);
	printf("%s\n", cha);
	printf("%s\n", str);
	
	return 0;
}
