#include <bits/stdc++.h>
using namespace std;

/* Problem : Find number of divisors of n where 1<=n<=10^18
 * 
 * https://codeforces.com/gym/100753/attachments/download/3533/2015-german-collegiate-programming-contest-gcpc-15-en.pdf
 * F. Divisions
 * 
 * Solution/Implementation is correct 
 * but codeforces doesn't support 128 bit it support only 64 bit
 * but if we use 64 bit it given wrong ans in range 10^18
 * 
 */



///These doesn't work anymore in codeforces as it support only 64 bit
//using u128 = __int128;
//using u64 = int64_t;

//typedef __uint128_t ui128;
typedef __int128_t u128;
typedef int64_t u64;
//typedef long long u128;


u64 pprimes[9999999], nPrime, x;
vector<bool> mark(9989083000, false);

/// Segmented Sieve
/// Description: Simple sieve of Eratosthenes with few optimizations.
/// It generates primes below 10^9 
/// Tutorial Link: https://github.com/kimwalisch/primesieve/wiki/Segmented-sieve-of-Eratosthenes


///set your CPU's L1 cache size(in bytes) 
const u64 L1D_CACHE_SIZE = 37768;

///Generate primes using the segmented sieve of Eratosthenes.
///This algorithm uses O(n log log n) operations and O(sqrt(n)) space.
///@param limit Sieve primes <= limit.
void segmented_sieve(u64 limit){
	u64 sqrtt = sqrt(limit);
	u64 segment_size = max(sqrtt, L1D_CACHE_SIZE);
	u64 count = (limit<2) ? 0 : 1;
	
	///we sieve primes >= 3
	u64 i = 3;
	u64 n = 3;
	u64 s = 3;
	
	vector<char> sieve(segment_size);
	vector<char> is_prime(sqrtt + 1, true);
	vector<u64> primes;
	vector<u64> multiples;
	
	pprimes[nPrime++] = 2;
	mark[2] = true;
	for(int64_t low = 0; low<=limit; low+=segment_size) {
		fill(sieve.begin(), sieve.end(), true);
		
		///current segment = [low, high]
		u64 high = low + segment_size - 1;
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
			u64 j = multiples[i];
			for(int64_t k = primes[i]*2; j<segment_size; j+=k){
				sieve[j] = false;
			}
			multiples[i] = j - segment_size;
		}
		
		for(; n<=high; n+=2){
			if(sieve[n-low]) {/// n is prime
				//cout<<count<<" <-count"<<endl;
				//count++;
				pprimes[nPrime++] = n;
				mark[n] =true;
				//if(count%500==1) printf("%ld\n", n);
			}
		}
	}
	//printf("%ld primes found.\n", count);
}


bool binarySearch(u64 n){
	u64 low = 0;
	u64 high = nPrime - 1;
	//printf("%lld ", n);
	//cout<<low<<" "<<high<<endl;
	while(low<=high){
		u64 mid = (low+high)/2;
		u64 k = pprimes[mid];
		//printf("%lld %lld %lld %lld\n", low, mid, high, k);
		if(k==n) return true;
		if(k>n){
			high = mid-1;
		}
		else low = mid+1;
	}
	return false;
}


u64 binpower(u64 base, u64 e, u64 mod){
	u64 res = 1;
	base%=mod;
	while(e){
		if(e&1) res = (u128)res*base%mod;
		base = (u128)base*base%mod;
		e>>=1;
	}
	return res;
}


bool check_composite(u64 n, u64 a, u64 d, int s){
	u64 x = binpower(a, d, n);
	
	if(x==1 or x==n-1) return false;
	for(int r=1;r<s;r++){
		x = (u128)x*x%n;
		if(x==n-1) return false;
	}
	return true;
}


bool MillerRabin(u64 n) {  ///returns true if n is prime else false
	if(n<2) return false;
	
	int r = 0;
	u64 d = n - 1;
	while((d&1)==0) {
		d>>=1;
		r++;
	}

	for(int a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}) {
		if(n==a) return true;
		if(check_composite(n, a, d, r)) return false;
	}
	return true;
}





u64 countDivisors(u64 n){
	if(n==1) return 1;
	
	//cout<<"good"<<endl;
	//vector<bool> primesquare(1000000000, false);
	//fill(primesquare.begin(), primesquare.end(), false);
	
	/*cout<<"bad"<<endl;
	printf("%lld\n", nPrime);
	for(u64 i=0;i<nPrime;i++){
		//cout<<"hey what happend?"<<endl;
		//printf("%lld ", pprimes[i]);
		u128 d = pprimes[i]*pprimes[i];
		if(d>n) break;
		//cout<<"Bujhlam na "<<i;
		//printf("  %lld\n", pprimes[i]);
		printf("%lld\n", d);
		primesquare[d] = true;
	}*/
	//cout<<"bad1"<<endl;
	u64 res = 1;
	//printf("%lld\n",pprimes[nPrime-1]);
	//cout<<"good"<<endl;
	for(int i=0; pprimes[i]<=cbrt(n) ; i++){
		//u128 dd = pprimes[i]*pprimes[i]*pprimes[i];
		//printf("%lld\n",dd); 
		//if(dd>n) break;
		
		u64 cnt = 1;
		//cout<<"valoi chollo"<<endl;
		//printf("%lld\n", pprimes[i]);
		while(n%pprimes[i]==0){
			n = n/pprimes[i];
			cnt = cnt + 1;
			//printf("%lld %ld\n", n, cnt);
		}
		
		res = res*cnt;
	}
	//cout<<"bad2"<<endl;
	
	/// check if sqrt(n) is a prime;
	//printf("%lld\n", n);
	u128 p = sqrt(n);
	//printf("%lld\n", p);
	bool flag = false;
	if(p*p==n) {
		flag = binarySearch(p);
	}
	//cout<<"wow"<<endl;
	
	
	if(MillerRabin(n)) { ///check if n is prime
		res = res*2;
	}
	else if (flag==true){  /// check if n is prime square or not
		res = res*3;
	}
	else if(n!=1) res = res*4;
	
	return res;
}



int main(){
	
	u64 limit = cbrt(9000000000000000000);  ///as max n is 10^18
	//cout<<limit<<endl;
	
	segmented_sieve(limit);
	//cout<<"finished"<<endl;
	
	
	scanf("%lld",&x);
	
	//bool falg = binarySearch(x); //yes kaj kore thikmoto :)
	//cout<<falg<<endl;
	
	printf("%ld\n",countDivisors(x));
	
		
	return 0;
}
