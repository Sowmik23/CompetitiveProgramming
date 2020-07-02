#include <bits/stdc++.h>

using namespace std;

#define ll long long 

//Use Binet's Formula : http://www.milefoot.com/math/discrete/sequences/binetformula.htm#:~:text=The%20explicit%20formula%20for%20the,of%20sequences%20in%20number%20theory.
//This helps for much larger number
//guide: https://stackoverflow.com/questions/2432669/test-if-a-number-is-fibonacci

bool isFibo(ll n){
	ll idx;
	double root5 = sqrt(5);
	double phi = (1+root5)/2;
	
	idx = floor(log(n*root5)/ log(phi) + 0.5);
	
	ll x = floor(pow(phi, idx)/root5 + 0.5);

	return (x==n);
}

//It can be done in different ways;
//another way is checking PerfectSquare

int isFibo2(ll n){
	ll a = 5*n*n + 4;
	ll b = 5*n*n - 4;
	
	ll s1 = sqrt(a);
	ll s2 = sqrt(b);
	
	if(s1*s1==a or s2*s2==b) return 1;
	else return 0;
}


int main(){
	ll t, n;
	cin>>t;
	while(t--){
		cin>>n;
		
		if(isFibo(n)) cout<<"IsFibo"<<endl;
		else cout<<"IsNotFibo"<<endl;
		
	}
	
	
	
	return 0;
}
