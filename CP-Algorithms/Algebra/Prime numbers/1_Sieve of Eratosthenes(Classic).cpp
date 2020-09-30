#include <bits/stdc++.h>
using namespace std;


/*#Bad!
 * Classic sieve of eratosthenes
 * 
 * Time Complexity: O(nloglogn) + O(n)
 * 
 * It works better for small n but it is best for memory complexity
 * 
 */	

typedef long long ll;

ll n;
vector<char> is_prime(n+1, true);

void prime(ll n){
	is_prime[0] = is_prime[1] = false;
	for(ll i=2;i*i<=n;i++){
		if(is_prime[i]) {
			for(ll j=i*i;j<=n;j+=i){
				is_prime[j] = false;
			}
		}
	}
}



int main(){
	
	cin>>n;
	
	prime(n); // determine prime from 2 to n
	
	for(ll i=0;i<=n;i++) {
		if(is_prime[i]) cout<<i<<endl;
	}
	
	
	return 0;
}
