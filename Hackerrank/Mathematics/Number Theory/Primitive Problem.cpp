#include <bits/stdc++.h>

using namespace std;

#define ll long long 

vector<ll>factors;


//This will provide the result of (base^exp)%mod in
// logarithmic time rather than quadratic time 
//without incurring overflow issues.

/*
ll power(ll a, ll b, ll mod){
	if(b==0) return 1;
	ll tmp = power(a, b>>1, mod)%mod;
	tmp = (tmp*tmp)%mod;
	
	if(b&1) tmp = tmp*a%mod;
	return tmp;
}
*/

//Easy version of power
int power(int a, int b, int m){
	int ans = 1;
	a = a%m;
	while(b){
		if(b&1) ans = (ans*a)%m;
		a = (a*a)%m;
		b = b>>1;
	}
	return (ans%m);
}


void primitiveRoot(ll p){
	ll n = p-1;
	//find all the unique prime factor of n-1
	
	//vector<ll>factors;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) {
			factors.push_back(i);
		}
		while(n%i==0){
			n/=i;
		}
	}
	if(n>=3){
		factors.push_back(n);
	}
	// now all the pime factors of n-1 is in "factors" vector
	
	//Now find the smallest primitive root
	//https://math.stackexchange.com/questions/124408/finding-a-primitive-root-of-a-prime-number
	ll smallest_primitive_number;
	for(ll i=2;i<p;i++){
		bool flag = true;
		
		for(auto j: factors){
			if(power(i, p/j, p)==1){
				flag = false;
				break;
			}
		}
		if(flag){
			smallest_primitive_number = i;
			break;
		}
	}
	
	cout<<smallest_primitive_number<<" ";
}

void totalNumberofPrimitiveRoots(ll p){
	ll x = p-1;
	for(auto i:factors){
		//cout<<factors[i]<<endl;
		x = x/i*(i-1);
	}
	
	cout<<x<<endl;
}


int main(){
	
	ll p;
	cin>>p;
	
	primitiveRoot(p);
	totalNumberofPrimitiveRoots(p);
	
	return 0;
}
