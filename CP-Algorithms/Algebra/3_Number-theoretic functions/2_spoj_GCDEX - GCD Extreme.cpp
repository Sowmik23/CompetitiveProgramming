#include <bits/stdc++.h>
using namespace std;


// Interesting problem
/// Tutorials: https://www.geeksforgeeks.org/summation-gcd-pairs-n/
/// Problem: https://www.spoj.com/problems/GCDEX/


#define MX 1000009
typedef long long ll;

ll phi[MX], res[MX];

void computTotient(){
	
	//precompute all phi values
	phi[1] = 1;
	for(int i=2;i<MX;i++){
		if(phi[i]==0) {
			phi[i] = i-1;
			for(int j=(i+i);j<MX;j+=i){
				if(phi[j]==0) phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}
	
	//precompute result for all nubers
	for(int i=1;i<MX;i++){
		for(int j=(i+i);j<MX;j+=i){
			res[j] +=i*phi[j/i];
		}
	}
	
	//add summation of previous calculated sum
	for(int i=1;i<MX;i++){
		 res[i] += res[i-1];
	 }
}
		
	

int main(){
	
	int n;
	
	computTotient();
	
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		
		printf("%lld\n", res[n]);
	}
	
	return 0;
}
