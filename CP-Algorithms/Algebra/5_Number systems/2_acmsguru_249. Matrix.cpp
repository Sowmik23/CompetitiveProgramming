#include <bits/stdc++.h>
using namespace std;


int decimalToGray(int n){
	return n^(n>>1);
}


int main(){
	
	int n, m;
	scanf("%d%d", &n, &m);
	
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<(1<<m);j++){
			printf("%d ", (decimalToGray(j)<<n | decimalToGray(i)) );
		}
		printf("\n");
	}
	
	
	return 0;
}
