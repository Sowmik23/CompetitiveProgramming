#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll mx = 5e6+1;
ll ans[mx];


void D(int n){
	ll sum = 0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			sum+=i;
			if(n/i!=i) sum+=(n/i);
		}
	}
	ans[n] =sum;
}


int main(){
	
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		if(ans[n]==0) D(n);
		printf("%lld\n", ans[n]-n);
	}
	
	return 0;
}
