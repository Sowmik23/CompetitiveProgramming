#include <bits/stdc++.h>
using namespace std;

/// Modular inverse exists if and only if a and m are 
/// relatively prime (i.e. gcd(a,m)=1).



/// Finding the Modular Inverse using Extended Euclidean algorithm
/// a⋅x + m⋅y = 1
/// in the case when m is not a prime number, we need to calculate
/// Euler phi function, which involves factorization of m,
/// which might be very hard. If the prime factorization of m
/// is known, then the complexity of this method is O(logm)
int x, y, d;

void extendedEuclid(int a, int b){
	if(b==0) {
		x = 1;
		y = 0;
		d = a;
		return ;
	}
	int x1, y1;
	extendedEuclid(b, a%b);
	x1 = y;
	y1 = x-y*(a/b);
	x = x1;
	y = y1;
	return ;
}


void modulerInv(int a, int m){
	
	extendedEuclid(a, m);
	int g = d;

	if(g!=1){
		cout<<"No solution!"<<endl;
	}
	else {
		x = (x%m + m)%m;
		cout<<x<<endl;
	}
}


/// Finding the modular inverse for every number modulo m
int inv[93335];

void findEvery_modulerInv(int m){
	
	inv[1] = 1;
	for(int i=2;i<m;i++){
		inv[i] = m - (m/i)*inv[m%i]%m;
	}
}

int main(){
	
	int a, m;
	scanf("%d%d", &a, &m);
	
	modulerInv(a, m);
	
	findEvery_modulerInv(m);
	for(int i=1;i<m;i++){
		cout<<inv[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
