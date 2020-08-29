#include <bits/stdc++.h>
using namespace std;

int fact(int x){
	if(x==0 or x==1) return 1;
	return x*fact(x-1);
}

int main(){
	
	double boys, girls;
	cin>>boys>>girls;
	
	double p = boys/(boys+girls);
	double q = 1.0-p;
	int n = 6, k = 3;
	
	
	double combination, b;
	double res = 0.0;
	for(int i=k;i<=n;i++){
		combination = fact(n)/(fact(i)*fact(n-i));
		b = pow(p,i)*pow(q, n-i);
		res+=(combination*b);
	}
	cout<<setprecision(3)<<fixed<<res<<endl;
	
	return 0;
}
