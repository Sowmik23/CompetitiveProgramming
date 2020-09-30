#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


ll pprimes[90000099], nPrime;

/// Set your CPU's L1 cache size(in bytes)
const int64_t L1D_CACHE_SIZE = 37768;


/// Segmented sieve of Eratosthenes
/// Time: O(n log log n)  Space: O(sqrt(n))
/// @param limit sieve prime <= limit
void segmented_sieve(int64_t limit) {
	int64_t sqrtt = (int64_t) sqrt(limit);
	int64_t segment_size = max(sqrtt, L1D_CACHE_SIZE);
	int64_t count = (limit<2) ? 0 : 1;
	
	
	/// we sieve primes >=3
	int64_t i = 3;
	int64_t n = 3;
	int64_t s = 3;
	
	
	vector<char> sieve(segment_size);
	vector<char> is_prime(sqrtt+1, true);
	vector<int64_t> primes;
	vector<int64_t> multiples;
	
	
	pprimes[nPrime++] = 2;
	for(int64_t low = 0; low<=limit; low+=segment_size){
		fill(sieve.begin(), sieve.end(), true);
		
		/// current segment = [low, high]
		int64_t high = low + segment_size - 1;
		high = min(high, limit);
		
		///generate sieving primes using simple sieve of Eratosthenes
		for(; i*i<=high; i+=2){
			if(is_prime[i]){
				for(int64_t j = i*i; j<=sqrtt; j+=i){
					is_prime[j] = false;
				}
			}
		}
		
		
		///initialize sieving primes for segmented sieve
		for(; s*s<=high; s+=2){
			if(is_prime[s]){
				primes.push_back(s);
				multiples.push_back(s*s - low);
			}
		}
		
		///sieve the current segment
		for(size_t i = 0; i<primes.size(); i++){
			int64_t j = multiples[i];
			for(int64_t k = primes[i]*2; j<segment_size; j+=k){
				sieve[j] = false;
			}
			multiples[i] = j-segment_size;
		}
		
		for(; n<=high; n+=2){
			if(sieve[n-low]) { ///n is prime
				//count++;
				pprimes[nPrime++] = n;
			}
		}
	}
}

void calculate(ll low, ll high){
	ll res = 0;
	for(ll i=low; i<high;i++){
		printf("%lld %lld = %lld\n", pprimes[i], pprimes[i+1], pprimes[i]*pprimes[i+1]);
		res+=(pprimes[i]*pprimes[i+1]);
	}
	printf("%lld\n",res);
}



int main(){
	
	segmented_sieve(100000000);
	cout<<"finished"<<endl;
	int t=9;
	ll l, r;
	scanf("%d",&t);
	
	
	while(t--){
		scanf("%lld %lld",&l, &r);
		
		ll low = lower_bound(pprimes, pprimes+nPrime, l)-pprimes;
		ll high = lower_bound(pprimes, pprimes+nPrime, r)-pprimes;
		
		//cout<<low<<" "<<high<<endl;
		if(pprimes[high]==r) calculate(low, high+1);
		else calculate(low, high);
	}
		
	
	return 0;
}
