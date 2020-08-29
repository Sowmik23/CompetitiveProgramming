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
	
	double x, y;
	cin>>x>>y;
	
	double res1 = n_standard_dev(mean, sd, x);
	//as we need to determine percentage so multiply result with 100
	cout<<setprecision(2)<<fixed<<(1.0 - res1)*100<<endl;
	
	double res2 = n_standard_dev(mean, sd, y);
	cout<<setprecision(2)<<fixed<<(1.0 - res2)*100<<endl<<res2*100<<endl;
	
	
	return 0;
}

