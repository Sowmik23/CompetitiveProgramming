#include <bits/stdc++.h>
using namespace std;


typedef unsigned long long ull;
//typedef long long ll;

//#define mx 5000000

const int mx = 5000000;
int phi[mx+1];
ull arr[mx+1];

void precalculateTotient(){
	for(int i=2;i<=mx;i++) phi[i]=i;
	
	for(int i=2;i<=mx;i++){
		if(phi[i]==i) {
			for(int j=i;j<=mx;j+=i){
				phi[j] -= phi[j]/i;
			}
		}
	}
	//test ok
	//for(int i=1;i<50;i++) cout<<phi[i]<<" ";
	
	//precalculate ans
	arr[1] = 0;
	//ull sum=0;
	for(int i=2;i<=mx;i++){
		arr[i] = phi[i];
		arr[i]*=arr[i];
		//sum+=d;
		arr[i] += arr[i-1];
		
		//printf("%llu   =  %lld   =  %llu \n", arr[i], d, sum);
	}
	//printf("%llu\n",sum);
}

int main(){
	
	precalculateTotient();
	//cout<<"finished"<<endl;
	//printf("%llu %llu\n", arr[5000000], arr[5000000]);
	
	int t, a, b;
	scanf("%d",&t);
	for(int cs=1;cs<=t;cs++) {
		scanf("%d%d",&a, &b);
		
		printf("Case %d: %llu\n", cs, arr[b]-arr[a-1]);
	}
	
	return 0;
}
