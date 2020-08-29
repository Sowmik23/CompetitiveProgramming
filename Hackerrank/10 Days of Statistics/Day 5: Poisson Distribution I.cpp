#include <bits/stdc++.h>
using namespace std;

//Poision distribution formula:

// P(x; μ) = (e^(-μ)) (μ^x) / x!


int fact(int x){
	if(x==0 or x==1) return 1;
	return x*fact(x-1);
}

int main(){
	
	double mean_mu, x;
	cin>>mean_mu>>x;
	
	double res = (exp(-mean_mu)*pow(mean_mu, x))/fact(x);
	
	cout<<setprecision(3)<<fixed<<res<<endl;
	
	return 0;
}




