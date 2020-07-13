#include <bits/stdc++.h>

using namespace std;

#define ll long long 


//tag: gcd();, find a divisor that divides n-1 number in an array;

ll prefix[1000005], suffix[1000005];

int main(){
	int n;
	cin>>n;
	ll arr[n];
	
	for(int i=0;i<n;i++) cin>>arr[i];
	
	if(n==1) {
		cout<<arr[0]+1<<endl;
		return 0;
	}
	
	for(int i=0;i<n;i++){
		prefix[i] = __gcd(arr[i], prefix[i-1]);
		//cout<<prefix[i]<<endl;
	}
	
	for(int i=n-1;i>=0;i--){
		suffix[i] = __gcd(suffix[i+1], arr[i]);
		//cout<<suffix[i]<<endl;
	}
	
	for(int i=0;i<n;i++){
		ll d = __gcd(prefix[i-1], suffix[i+1]);
		//cout<<d<<endl;
		if(arr[i]%d!=0) {
			cout<<d<<endl;
			return 0;
		}
	}
	
	return 0;
}
