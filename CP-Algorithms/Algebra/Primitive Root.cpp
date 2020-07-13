#include <bits/stdc++.h>

using namespace std;

//this determines one primitive root of a prime number

//The smallest primitive root of prime p.
//The total number of primitive roots of prime p .


//This will provide the result of (base^exp)%mod in
// logarithmic time rather than quadratic time 
//without incurring overflow issues.

/*
int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}
* */

//Easy version of powmod
int powmod(int a, int b, int m){
	int ans = 1;
	a = a%m;
	while(b){
		if(b&1) ans = (ans*a)%m;
		a = (a*a)%m;
		b = b>>1;
	}
	return (ans%m);
}

int generator (int p) {
	//find all the unique prime factor of n-1
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

	//find the smallest primitve root 
    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

int main(){
	
	int p;
	cin>>p;
	int x = generator(p);
	
	cout<<x<<endl;
	
	return 0;
}
