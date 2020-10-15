#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

#define MX 200010

ll phi[MX];

void phi_1_to_n(){
	
	phi[0] = 0;
	phi[1] = 1;
	for(ll i=2;i<=MX;i++){
		phi[i] = i;
	}
	
	for(ll i=2;i<=MX;i++){
		if(phi[i]==i){
			for(ll j=i;j<=MX;j+=i){
				phi[j] = phi[j]/i*(i-1);
			}
		}
		phi[i]+=phi[i-1];
	}
	
	/*for(int i=0;i<=10;i++){
		cout<<phi[i]<<" ";
	}
	cout<<endl;*/
}


int main(){
	
	phi_1_to_n();
	
	ll n;
	while(1){
		cin>>n;
		if(n==0) break;
		if(n==1) {
			cout<<"0/1"<<endl;
			continue;
		}
		if(n==2){
			cout<<"1/1"<<endl;
			continue;
		}
		
		n = n - 1;
		
		ll lb = lower_bound(phi, phi+MX, n) - phi;
		
		ll d = n - phi[lb-1];
		//cout<<lb<<" "<<phi[lb-1]<<" "<<d<<endl;
		int cnt=0;
		
		for(ll i=1;i<=lb;i++){
			if(__gcd(i, lb)==1){
				cnt++;
				if(cnt==d) {
					cout<<i<<"/"<<lb<<endl;
					break;
				}
			}
		}
		
	}
		
	
	return 0;
}
