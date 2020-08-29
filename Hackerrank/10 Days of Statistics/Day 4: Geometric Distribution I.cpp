#include <bits/stdc++.h>
using namespace std;

int fact(int x){
	if(x==0 or x==1) return 1;
	return x*fact(x-1);
}

int main(){
	
	double numerator, denominator, inspection;
	cin>>numerator>>denominator;
	cin>>inspection;
	
	double p = numerator/denominator;
	double q = 1.0 - p;
	
	double res = pow(q, inspection-1)*p;
	
	cout<<setprecision(3)<<fixed<<res<<endl;
	
	return 0;
}


