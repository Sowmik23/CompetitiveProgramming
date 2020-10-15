#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const int mx = 1e5;
int phi[mx+3];
ll arr[mx+9];

void precalculateTotient(){
	phi[1] = 1;
	for(int i=2;i<=mx;i++) phi[i] = i;
	
	for(int i=2;i<=mx;i++){
		if(phi[i]==i){
			for(int j=i;j<=mx;j+=i){
				phi[j]-=phi[j]/i;
			}
		}
	}
}

void solve(){
	ll sum =0, d = 0;
	for(int i=1;i<=mx;i++){
		d+= phi[i];
		sum+=i;
		
		arr[i] = abs(d-sum);
	}
}


int main(){
	
	precalculateTotient();
	
	solve();
	
	int t, n;
	scanf("%d",&t);
	for(int cs=1;cs<=t;cs++) {
		scanf("%d",&n);
		
		printf("Case %d: %lld\n", cs, arr[n]);
		
	}
	
	
	return 0;
}
