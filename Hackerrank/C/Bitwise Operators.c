#include <stdio.h>


int main(){
	
	
	int n, k;
	//n = 3, k =3;
	
	scanf("%d%d", &n, &k);
	
	int maxAnd = 0, maxOr = 0, maxXor = 0;
	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			
			int and = i&j;
			int or = i|j;
			int xor = i^j;
			
			if(and<k) {
				if(maxAnd<and) maxAnd = and;
			}
			if(or<k) {
				if(maxOr<or) maxOr = or;
			}
			if(xor<k) {
				if(maxXor<xor) maxXor = xor;
			}
			//printf("%d %d %d\n", and, or, xor);
		}
	}
	
	printf("%d\n%d\n%d\n", maxAnd, maxOr, maxXor);
	
	
	return 0;
}
