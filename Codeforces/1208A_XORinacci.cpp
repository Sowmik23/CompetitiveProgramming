#include <bits/stdc++.h>

using namespace std;

long long int a,b;

int XORinacci(int n){
	
	if(n==0) return a;
	if(n==1) return b;
	return (XORinacci(n-1) xor XORinacci(n-2));
	
}


int main(){
	
	long long int n,t;
	
	scanf("%lld",&t);
	while(t--){
		
		scanf("%lld%lld%lld",&a,&b,&n);
		
		n = n%3; 
		if(n==0) printf("%lld\n",a);
		else if(n==1) printf("%lld\n",b);
		else printf("%lld\n",a xor b);
		
	}
	
	return 0;
	
}
