#include <stdio.h>

int main(){
	
	
	int n;
	scanf("%d", &n);
	int arr[n+1];
	int brr[n+1];
	
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0;i<n;i++){
		brr[i] = arr[n-i-1];
	}
	
	for(int i=0;i<n;i++) printf("%d ", brr[i]);
	printf("\n");
	
	
	
	return 0;
}
