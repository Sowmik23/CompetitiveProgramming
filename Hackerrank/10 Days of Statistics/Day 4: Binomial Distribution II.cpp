#include <bits/stdc++.h>
using namespace std;

int fact(int x){
	if(x==0 or x==1) return 1;
	return x*fact(x-1);
}

int main(){
	
	double percent_of_defect, size_of_piston;
	cin>>percent_of_defect>>size_of_piston;
	
	double p = percent_of_defect/100.0;
	double q = 1.0 - (percent_of_defect/100.0);
	double n = size_of_piston;
	
	
	double combination, b;
	double res = 0.0;
	
	for(int i=0;i<=2;i++){
		combination = fact(n)/(fact(i)*fact(n-i));
		b = pow(p,i)*pow(q, n-i);
		res+=(combination*b);
	}
	cout<<setprecision(3)<<fixed<<res<<endl;
	
	res = 0.0;
	for(int i=2;i<=n;i++){
		combination = fact(n)/(fact(i)*fact(n-i));
		b = pow(p,i)*pow(q, n-i);
		res+=(combination*b);
	}
	cout<<setprecision(3)<<fixed<<res<<endl;
	
	return 0;
}

