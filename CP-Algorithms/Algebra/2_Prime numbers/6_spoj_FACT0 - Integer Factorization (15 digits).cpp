#include <bits/stdc++.h>
using namespace std;


/// Problem: https://www.spoj.com/problems/FACT0/
/// Integer Factorization 15 digits



using u64 = int64_t;

vector<u64> pprimes;


///set your CPU's L1 cache size(in bytes) 
const int64_t L1D_CACHE_SIZE = 32768;


///Generate primes using the segmented sieve of Eratosthenes.
///This algorithm uses O(n log log n) operations and O(sqrt(n)) space.
///@param limit Sieve primes <= limit.
void segmented_sieve(int64_t limit){
	int64_t sqrtt = (int64_t) sqrt(limit);
	int64_t segment_size = max(sqrtt, L1D_CACHE_SIZE);
	int64_t count = (limit<2) ? 0 : 1;
	
	///we sieve primes >= 3
	int64_t i = 3;
	int64_t n = 3;
	int64_t s = 3;
	
	vector<char> sieve(segment_size);
	vector<char> is_prime(sqrtt + 1, true);
	vector<int64_t> primes;
	vector<int64_t> multiples;
	
	pprimes.emplace_back(2);

	for(int64_t low = 0; low<=limit; low+=segment_size) {
		fill(sieve.begin(), sieve.end(), true);
		
		///current segment = [low, high]
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
		for(size_t i=0;i<primes.size();i++){
			int64_t j = multiples[i];
			for(int64_t k = primes[i]*2; j<segment_size; j+=k){
				sieve[j] = false;
			}
			multiples[i] = j - segment_size;
		}
		
		for(; n<=high; n+=2){
			if(sieve[n-low]) {/// n is prime
				//cout<<count<<" <-count"<<endl;
				//count++;
				//pprimes[nPrime++] = n;
				pprimes.emplace_back(n);
				//if(count%500==1) printf("%ld\n", n);
			}
		}
	}
	//printf("%ld primes found.\n", count);
}


void integerFactorization(u64 n){
	vector<u64> factorization;
	for(u64 i : pprimes){
		if(i*i>n) break;
		
		while(n%i==0) {
			factorization.push_back(i);
			n = n/i;
		}
	}
	if(n>1) factorization.push_back(n);
	
	//for(auto i: factorization) cout<<" "<<i<<" ";
	//cout<<endl;
	
	int len = factorization.size();
	
	int cnt=1;
	for(int i=1;i<len;i++){
		if(factorization[i]==factorization[i-1]) cnt++;
		else {
			cout<<factorization[i-1]<<"^"<<cnt<<" ";
			cnt=1;
		}
	}
	cout<<factorization[len-1]<<"^"<<cnt<<endl;
}
	

int main(){
	
	segmented_sieve(35000000);	//sqrt of 15 digits
	//cout<<"finish"<<endl;
	
	u64 n;
	while(1){
		cin>>n;
		if(n==0) break;
		
		integerFactorization(n);
		
	}
	
	
	return 0;
}
