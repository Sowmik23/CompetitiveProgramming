#include <bits/stdc++.h>
using namespace std;


#define MX (2000000>>5) + 1   //it means dividing x by 2^5;
#define GET(x) (mark[(x)>>5]>>((x)&31)&1)  
#define SET(x) (mark[(x)>>5] |= 1<<((x)&31))

int mark[MX], phi[2000009], depth_phi[2000009], dp[2000009];

/// Use of SET and GET in cpp;

/// The get method will return a pointer to the choice item 
/// only if it is the selected item; otherwise it will return null.
/// The is method returns a boolean value of true if the element 
/// is the selected element or false otherwise. The set method 
/// sets the element to the given value and selects it by setting 
/// the t value.



void sieve(){
	
	SET(1);
	for(int i=2;i<=2000000;i++){
		if(!GET(i)){
			for(int j=i;j<=2000000;j+=i){
				phi[j] = phi[j]/i*(i-1);
				SET(j);
			}
		}
	}
}



int main(){
	
	int t, m, n;
	
	for(int i=2;i<=2000000;i++) phi[i] = i;
	
	sieve();
	
	for(int i=2;i<=2000000;i++){
		depth_phi[i] = 1 + depth_phi[phi[i]];
		dp[i] = dp[i-1] + depth_phi[i];
	}
	
	cin>>t;
	while(t--){
		cin>>m>>n;
		
		cout<<dp[n] - dp[m-1]<<endl;
	}
	
	
	
	return 0;
}
