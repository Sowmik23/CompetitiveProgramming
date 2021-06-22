#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll compute(int m, int n){
	//ll val = ((m-n+1)*(m+n))/2;
	
	//ll val = ((n+m)*(n-m)*(n+m))/2;
	
	ll a = n*(n+1)/2;
	ll b = m*(m+1)/2;
	
	ll val = a - b + m;
	return val;
}


int main(){
	
	int t;
	ll g;
	scanf("%d", &t);
	for(int test = 1;test<=t;test++){
		scanf("%lld", &g);
		
		int res = 1;
		
		for(int i = 1;i<=g;i++){
			ll d = compute(i, g);
			cout<<d<<endl;
			if(d==g){
				res++;
				cout<<d<<" "<<i<<"kk";
			}
		}
		
		printf("Case #%d: %d\n", test, res);
	}
	
	
	return 0;
}
