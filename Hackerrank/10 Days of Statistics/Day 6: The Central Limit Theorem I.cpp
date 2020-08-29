#include <bits/stdc++.h>
using namespace std;


int main(){
	
	double max_weight, no_of_box, mean, sd;
	
	cin>>max_weight>>no_of_box>>mean>>sd;
	
	double Z = (max_weight - no_of_box*mean)/(sd*sqrt(no_of_box));
	
	double res = 0.5*(1+erf(Z/sqrt(2)));
	cout<<setprecision(4)<<fixed<<res<<endl;
	
	
	return 0;
}


