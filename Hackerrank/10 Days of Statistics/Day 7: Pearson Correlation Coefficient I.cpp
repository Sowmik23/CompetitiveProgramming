#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	double x[n], y[n];
	
	double sm1 = 0.0, sm2 = 0.0;
	for(int i=0;i<n;i++) {
		cin>>x[i];
		sm1+=x[i];
	}
	for(int i=0;i<n;i++){ 
		cin>>y[i];
		sm2+=y[i];
	}
	
	double mu_X = sm1/n;
	double mu_Y = sm2/n;
	
	double s1=0.0, sum1=0.0, sum2=0.0;
	for(int i=0;i<n;i++){
		s1+= ((x[i] - mu_X)*(y[i] - mu_Y));
		sum1+= pow((x[i] - mu_X), 2);
		sum2+= pow((y[i]- mu_Y), 2);
	}
	
	double sigma_X = sqrt(sum1/n);
	double sigma_Y = sqrt(sum2/n);
	
	//PCC === Pearson Correlation Coefficient
	double PCC;
	
	PCC = s1/(n*sigma_X*sigma_Y);
	cout<<setprecision(3)<<fixed<<PCC<<endl;
	
	return 0;
}
