#include <bits/stdc++.h>
using namespace std;

//TLE

typedef long long ll;
const ll mx = 1e7;

ll phi[mx], arr[mx];


bool check(ll n, ll m){
	string str1 = to_string(n);
	string str2 = to_string(m);
	
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	
	//cout<<str1<<" "<<str2<<endl;
	return str1==str2;
}



void precalculateTotient(){
	
	// precalculate all phi values
	phi[1] = 1;
	for(ll i=2;i<mx;i++){
		if(phi[i]==0){
			phi[i] = i-1;
			for(ll j=(i+i);j<mx;j+=i){
				if(phi[j]==0) phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}
	//for(int i=0;i<100;i++) cout<<phi[i]<<" ";
	int k = 0;
	for(int i=2;i<mx;i++){
		if(check(i, phi[i])){
			arr[i] = i;
			k = i;
		}
		arr[i] =k;
	}
	
	//test
	//for(int i=0;i<300;i++) cout<<arr[i]<<" ";
	
}


int main(){

	precalculateTotient();	
	//cout<<"completed"<<endl;
	
	ll n;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		
		printf("%lld\n", arr[n]);
	}
	
	
	return 0;
}
