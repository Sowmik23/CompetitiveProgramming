#include <bits/stdc++.h>
using namespace std;

int Factorial(int n){
	cout<<"Calculating F("<<n<<")"<<endl;
	if(n==0) return 1;
	
	//return n*Factorial(n-1);
	int f = n*Factorial(n-1);
	cout<<"F("<<n<<") = "<<f<<endl;
	return f;
}


int main(){
	
	//iterative solution
	
	int n = 5;
	int ans = 1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans<<endl;
	
	
	//recursive solution
	int res = Factorial(5);
	cout<<res<<endl;
	
	return 0;
}
