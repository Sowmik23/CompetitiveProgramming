#include <stdio.h>
#include <string.h>

int main(){
	
	
	char str[1001];
	
	scanf("%[^\n]", str);
	
	int len = strlen(str);
	
	
	for(int i=0;i<len;i++){
		if(str[i]==' ') {
			printf("\n");
		}
		else printf("%c",str[i]);
	}
	
	return 0;
}
