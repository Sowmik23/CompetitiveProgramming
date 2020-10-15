#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


//Verdict: Time Limit Exceed

int64_t pprimes[9000009], nPrime;
vector<bool>mark(100000005, false);

//map<int64_t, pair<int64_t, int64_t>> mp;


/*
/// General sieve can not solve this problem as n = 10^8
/// We need to use segmented sieve
*/

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
	
	
	//pprimes[nPrime++] = 2;
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
				mark[n] = true;
			}
		}
	}
}




//map<ll, pair<ll, ll>> mp;

/*
void find_position(){
	int64_t row=1, col=1;
	mp[2] = make_pair(row, col);
	col+=1;
	//cout<<nPrime<<endl;
	for(int64_t i=3; i<=100000000;i+=2){
		if(row<col) {
			row+= 1;
			col = 1;
		}
		if(mark[i]) {
			mp[i] = make_pair(row, col);
			col+=1;
		}
	}
}
*/

ll ncr(ll n){
	ll r = 2;
	if(r>n-r) r = n-r; ///because C(n,r) = C(n, n-r)
	ll ans = 1;
	
	for(ll i=1;i<=r;i++){
		ans*= n-r+i;
		ans/=i;
	}
	return ans;
}



int main(){
	
	//segmented_sieve(100000000);
	cout<<"finish"<<endl;
	//find_position();
	//cout<<"finished2"<<endl;
	int t;
	//scanf("%d",&t);
	ll n;
	
	ll x = ncr(7);
	cout<<x<<endl;
	
	//while(t--){
		//scanf("%lld",&n);
		
				
	//}
	
	return 0;
}
