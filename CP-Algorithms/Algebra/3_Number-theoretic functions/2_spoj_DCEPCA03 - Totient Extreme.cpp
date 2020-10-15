#include <bits/stdc++.h>
using namespace std;


/*
H=0;
For (i=1; i<=n; i++) {
    For (j=1; j<=n; j++) {
        H = H + totient(i) * totient(j);
    }
}*/

/// By Euler totient function property we can write the above H as below: 

///Learn properties of Euler Totient Function:
/// H = (phi[1] + phi[2] + ....+phi[n])^2


typedef long long ll;
const int mx = 1e4;
int phi[mx+4];

void precalculateTotient(){
	phi[1]= 1;
	for(int i=2;i<=mx;i++) phi[i] = i;
	
	for(int i=2;i<=mx;i++){
		if(phi[i]==i){
			for( int j=i;j<=mx;j+=i){
				phi[j] -=phi[j]/i;
			}
		}
	}
}


void Solve(int n){
	ll H = 0;
	for(int i=1;i<=n;i++){
		H+=phi[i];
	}	
	H*=H;
	printf("%lld\n", H);
}



int main(){
	
	precalculateTotient();
	
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
	
		Solve(n);
	}

	return 0;
}
