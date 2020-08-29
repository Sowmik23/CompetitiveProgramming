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
	
	double res=0.0;
	for(int i=0;i<5;i++){
		res += pow(q, i)*p;
	}
	cout<<setprecision(3)<<fixed<<res<<endl;
	
	return 0;
}



