#include <bits/stdc++.h>
using namespace std;


int main(){
	
	double available_tickets, no_of_students, mean, sd;
	
	cin>>available_tickets>>no_of_students>>mean>>sd;
	
	double Z = (available_tickets - no_of_students*mean)/(sd*sqrt(no_of_students));
	
	double res = 0.5*(1+erf(Z/sqrt(2)));
	cout<<setprecision(4)<<fixed<<res<<endl;
	
	
	return 0;
}



