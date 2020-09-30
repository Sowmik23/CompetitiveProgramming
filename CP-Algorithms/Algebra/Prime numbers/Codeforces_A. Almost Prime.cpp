#include <bits/stdc++.h>
using namespace std;

int primes[10000], nPrime;
vector<bool> mark(3009, true);


void sieve(){
	int n = 3001;
	mark[0] =mark[1]= false;
	for(int i=4;i<=n;i+=2) mark[i] = false;
	for(int i=3;i*i<=n;i+=2){
		if(mark[i]){
			for(int j=i*i;j<=n;j+=(2*i)) mark[j] = false;
		}
	}
	for(int i=2;i<=n;i++){
		if(mark[i]) primes[nPrime++] = i;
	}
}


bool calculate(int n){
	int cnt=0;
	for(int i=0;primes[i]<=n;i++) {
		if(n%primes[i]==0) cnt++;
	}
	if(cnt==2)  return true;
	else return false;
}

int main(){
	sieve();
	int n;
	scanf("%d",&n);
	
	int cnt = 0;
	for(int i=1;i<=n;i++) {
		if(calculate(i)) cnt++;
	}
	printf("%d\n", cnt);
	
	return 0;
}
