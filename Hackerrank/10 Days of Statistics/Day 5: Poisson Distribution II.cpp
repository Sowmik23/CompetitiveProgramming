#include <bits/stdc++.h>
using namespace std;

//Poision distribution formula:

// P(x; μ) = (e^(-μ)) (μ^x) / x!

/*
 * Ca = 160 + 40X^2 can be written as:
 * 
 * 160 + 40 (theta + theta^2)
 * 
 * 
 * 
*/


int main(){
	
	double mean_muA, mean_muB;
	cin>>mean_muA>>mean_muB;
	
	double res1 = 160 + 40 *(mean_muA + pow(mean_muA, 2));
	cout<<setprecision(3)<<fixed<<res1<<endl;
	
	double res2 = 128 + 40 *(mean_muB + pow(mean_muB, 2));
	cout<<setprecision(3)<<fixed<<res2<<endl;
	
	
	return 0;
}





