#include <bits/stdc++.h>
using namespace std;


/// Interesting problem: Fast sieve() + Euler totient()


#define HAS(_n) (pbits[(_n)>>5] & (1u << ((_n) & 0x1f)))
#define SET(_n) (pbits[(_n)>>5] |= (1u << ((_n) & 0x1f)))

typedef long long ll;
typedef unsigned long long u64;


const int LIMIT = 100000000;

unsigned int pbits[LIMIT/32+1];
int pc, pr[LIMIT/10];

void fastSieve( void )
{
  int i, j;
  pc = 0;
  for( i = 2; i <= LIMIT; ++i)
  {
    if( !HAS( i ) ) pr[pc++] = i;
    for( j = 0; j < pc && i * pr[j] <= LIMIT; ++j)
    {
      int num = i * pr[j];
      SET( num );
      if( i % pr[j] == 0 ) break;
    }
  }
}


/// Find Sum of Divisors of n(totient function)
void Dd(u64 n){
	u64 tmp = n;
	u64 res = 1;
	for(int i=0;i<pc and (u64)pr[i]*pr[i]<=n;i++){
		int cnt =0;
		u64 sum = 1, pw = 1;
		while(n%pr[i]==0){
			pw*=pr[i];
			sum+=pw;
			cnt++;
			n/=pr[i];
		}
		if(cnt>0) res*= sum;
	}
	if(n>1) res*=(n+1);
	
	res = res-tmp;
	
	printf("%llu\n", res);
} 



int main(){
	
	cout<<"Kept as wrong ans for keeping it in todo list"<<endl;
	fastSieve();
	//cout<<"finished"<<endl;
	
	ll t, n;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		
		Dd(n);
		
	}
	
	return 0;
}
