#include <bits/stdc++.h>
using namespace std;

#define pi 3.14159

//there are two ways to solve this problem
/*
 * 	CDF --- Comullative Distribution Function and 
 *  PDF --- Probability Distributin Function
 * 
 * It is easier to solve using CDF  but need to use 
 * z-score values in PDF 
*/
 


double n_standard_dev(double mean, double sd, double x){
	
	return 0.5*(1 + erf((x-mean)/(sd*pow(2.0, 0.5))) );
}

int main(){
	
	double mean, sd;
	cin>>mean>>sd;
	
	double x, y, z;
	cin>>x;
	cin>>y>>z;
	
	double res1 = n_standard_dev(mean, sd, x);
	cout<<setprecision(3)<<fixed<<res1<<endl;
	
	double res2 = n_standard_dev(mean, sd, z) - n_standard_dev(mean, sd, y);
	cout<<setprecision(3)<<fixed<<res2<<endl;
	
	
	return 0;
}
