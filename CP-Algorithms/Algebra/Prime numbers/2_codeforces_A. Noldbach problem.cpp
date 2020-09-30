#include <bits/stdc++.h>
using namespace std;

int primes[1000], nPrime;
vector<bool> mark(1005, true);


void sieve() {
	mark[0] = mark[1] = false;
	for(int i=4;i<=1000;i+=2)mark[i] = false;
	
	for(int i=3;i*i<=1000;i+=2){
		if(mark[i]){
			for(int j =i*i;j<=1000;j+=(2*i)){
				mark[j] = false;
			}
		}
	}
	for(int i=2;i<=1000;i++){
		if(mark[i]) primes[nPrime++] = i;
	}
}



bool calculate(int n, int k){
	int cnt = 0;
	for(int i=2;primes[i]<=n; i++){
		for(int j=0;primes[j] + primes[j+1]<primes[i];j++) {
			//printf("%d = %d + %d + 1\n",primes[i], primes[j], primes[j+1]);
			if(primes[i] == primes[j] + primes[j+1] + 1) {
				cnt++;
				if(cnt>k) return true;
			}
		}
	}
	if(cnt==k) return true;
	else return false;
}


int main(){
	
	sieve();
	
	int n, k;
	scanf("%d%d",&n,&k);
	
	if(calculate(n, k)) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
