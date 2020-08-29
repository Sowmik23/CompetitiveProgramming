#include <bits/stdc++.h>
using namespace std;

//Regression in c++

int main(){
	
	int n=5;
	
	int x, y;
	
	vector<double> v1, v2;
	double sumX=0.0, sumY=0.0, sq_sumX=0.0, sumXY=0.0;
	
	for(int i=0;i<5;i++){
		cin>>x;
		v1.push_back(x);
		sumX+=x;
		sq_sumX+=x*x;
		
		cin>>y;
		v2.push_back(y);
		sumY+=y;
		sumXY+=x*y;
	}
	
	double meanX = sumX/n;
	double meanY = sumY/n;
	
	double coB = ((n*sumXY) - (sumX*sumY))/((n*sq_sumX) - (sumX*sumX));
	double coA = meanY - coB*meanX;
	
	cout<<setprecision(3)<<fixed<<(coA + coB*80)<<endl;
	
	
	return 0;
}
