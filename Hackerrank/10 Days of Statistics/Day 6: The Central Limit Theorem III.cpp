#include <bits/stdc++.h>
using namespace std;


int main(){
	
	double sample, mean, sd, distribution, z_score;
	
	cin>>sample>>mean>>sd>>distribution>>z_score;
	
	double r = sd/sqrt(sample);
	
	cout<<setprecision(2)<<fixed<<mean - r*z_score<<endl;
	cout<<setprecision(2)<<fixed<<mean + r*z_score<<endl;
	
	
	return 0;
}



		
