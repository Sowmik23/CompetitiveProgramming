#include <bits/stdc++.h>

using namespace std;

#define ll long long

//identify if smith number
//number digits summation == all its factors digits summation

vector<ll>factors;

ll sumofPrimeFactors(ll n){
	for(ll i=2;i*i<=n;i++){
		while(n%i==0){
			n/=i;
			//cout<<i<<endl;
			factors.push_back(i);
		}
	}
	//cout<<n<<endl;
	if(n>=3) factors.push_back(n);
	
	ll sum = 0;
	for(auto &fact: factors){
		//cout<< fact<<endl;
		while(fact>0){
			sum+=(fact%10);
			fact/=10;
		}
	}

	return sum;
}


int main(){
	
	ll n;
	cin>>n;
	
	ll x = sumofPrimeFactors(n);
	//cout<<x<<endl;
	
	ll sum=0;
	
	while(n>0){
		sum+=(n%10);
		n/=10;
	}
	//cout<<sum<<endl;
	
	if(x==sum) cout<<"1\n";
	else cout<<"0\n";
	
	return 0;
}
