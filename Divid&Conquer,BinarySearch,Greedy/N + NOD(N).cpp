#include <bits/stdc++.h>
using namespace std;   //TLE khay ....;)

long long int prime[1000009],nPrime, mark[100009];
long long int divisor[1000009],num[1000009];

void sieve(long long int n)
{
	int limit = sqrt(n) + 2;
	mark[0]=mark[1]=1;  //as 1 and 0 are not prime.
	for(int i=4;i<=n;i+=2)
	{
		mark[i]=1;     //as almost all the evens are not prime.
	}
	prime[nPrime++]=2;
	for(int i=3;i<=n;i+=2)
	{
		if(!mark[i])
		{
			prime[nPrime++]=i;
			if(i<=limit)
			{
				for(int j=i*i;j<=n;j+=i*2)
				{
					mark[j]=1;   //j are not prime.
				}
			}
		}
	}
}

bool checkPrime(long long x)
{
	long long d = lower_bound(prime,prime+nPrime,x)-prime;
	if(prime[d]==x) return true;
	else return false;
}

bool checkCoprime(long long x)
{
	long long d = sqrt(x);
	if(checkPrime(d)==true and d*d==x) return true;
	else return false;
}

/*find the number of divisors form 1 to 1000009 
and store in divisor[i]=number of divisors*/

void divisors()
{
	long long div=2,cnt,k;
	divisor[1]=1;
	for(long long i=2;i<1000009;i++)
	{
		//m = sqrt(i) + 2;
		div=1;
		k=i;
		cnt=1;
		if(checkPrime(i)==true) div=2;
		else if(checkCoprime(i)==true) div=3;
		else 
		{
			for(long long j=0;prime[j]*prime[j]<=k;j++)
			{
				cnt=0;
				while(k%prime[j]==0)
				{
					cnt++;
					k/=prime[j];
				}
				div*=(cnt+1);
			}
			if(k>1) div*=2;
		}
		divisor[i]=div;
		cout<<i<<" "<<divisor[i]<<endl;
	}
}

void nu()
{
	num[1]=1;
	for(nPrime=2;nPrime<1000000;nPrime++)
	{
		//num[nPrime] = n + n er number of divisor 
		num[nPrime] = num[nPrime-1] + divisor[num[nPrime-1]];
		//cout<<nPrime<<" "<<num[nPrime]<<endl;
		if(num[nPrime]>1000000) break;
	}
}


int main()
{
	sieve(1000009);
	
	/*for(int i=0;i<nPrime;i++)
	{
		cout<<prime[i]<<" ";
	}
	cout<<checkPrime(4)<<endl;
	cout<<checkPrime(11)<<endl;
	
	cout<<checkCoprime(4)<<endl;
	cout<<checkCoprime(11)<<endl;*/
	
	divisors();
	nu();
	
	long long int n,x,y;
	scanf("%lld",&n);
	for(int k=1;k<=n;k++)
	{
		scanf("%lld%lld",&x,&y);
		long long a = lower_bound(num,num+nPrime,x)-num;
		long long b = upper_bound(num,num+nPrime,y)-num;
		printf("Case %d: %lld\n",k,b-a);
	}
	
	return 0;
}

