#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


/// Segmented Sieve
/// Description: Simple sieve of Eratosthenes with few optimizations.
/// It generates primes below 10^9 
/// Tutorial Link: https://github.com/kimwalisch/primesieve/wiki/Segmented-sieve-of-Eratosthenes


///set your CPU's L1 cache size(in bytes) 
const int64_t L1D_CACHE_SIZE = 32768;


//to store primes 
int64_t ppprimes[9000000], nPrime;
int64_t binary[150000009];


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
	
	
	ppprimes[nPrime++] = 2;
	
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
				
				ppprimes[nPrime++] = n;
				//pprimes.emplace_back(n);
				count++;
				//if(count%500==1) printf("%ld\n", n);
			}
		}
	}
	//printf("%ld primes found.\n", count);
}



int64_t cnt =0;
void preCalculate(){
	int64_t idx=1;
	
	for(int64_t i=0;i<nPrime;i++){
		int x = ppprimes[i];
		  
		//cout<<x<<" ";
		/*
		while(x>0){		///this will count 2->01
			int y = x&1 		///3->11	
			//cout<<y;			///5->101 7->111 11->1011  which is worng
			if(y==1) cnt++;
			binary[idx++] = cnt;
			x = x>>1;
		}
		//cout<<endl;
		*/
		int flag = 0;
		for(int j=0;j<32;j++){  ///Here is the main ninja techinque
			if(x<0){
				cnt++;
				binary[idx++] = cnt;
				flag = 1;
			}
			else if(flag) {
				binary[idx++] = cnt;
			}
			//cout<<x;
			x = x<<1;
		}
		//cout<<endl;
		//cout<<binary[1]<<endl;
		//cout<<binary[2]<<endl;
		//cout<<binary[3]<<endl;
		//cout<<binary[4]<<endl;
		
		//printf("%lld ",cnt);
	}
	//printf("idx = %ld\n nPrime=%lld\ncnt=%d", idx, nPrime, cnt);
}



int main(int argc, char** argv){
	
	if(argc>=2) { 
		segmented_sieve(atoll(argv[1]));
	}
	else {
		segmented_sieve(101865020);
	}
	//cout<<"Completed"<<endl;
	
	preCalculate();
	//cout<<"Completed2"<<endl;
	
	unsigned t, n;
	
	cin>>t;
	while(t--){
		cin>>n;
		
		if(n==0) printf("0\n");
		else if(n==1) printf("1\n");
		else printf("%u\n", binary[n]);
	}	
	
	
	return 0;
}
