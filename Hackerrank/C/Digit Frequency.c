#include <stdio.h>
#include <string.h>


int main(){
	
	char str[1001];
	
	scanf("%[^\n]", str);
	
	int len = strlen(str);
	
	int arr[10] = {0};
	for(int i=0;i<len;i++){
		if(str[i]>='0' && str[i]<='9'){
			int digit = str[i] - '0';
			//printf("%d\n", digit);
			arr[digit]++;
		}
	}
	
	for(int i=0;i<10;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}
