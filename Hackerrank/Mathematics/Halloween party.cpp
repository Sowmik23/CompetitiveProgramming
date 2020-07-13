#include <bits/stdc++.h>

using namespace std;

//maximum number of pieces that can be obtained for each test
//dividing cake 


int main(){
	
	int t;
	long long k;
	cin>>t;
	while(t--){
		cin>>k;
		long long int x = k/2;
		long long int y = (k+1)/2;
		
		cout<<x*y<<endl;
	}
	
	
	return 0;
}
