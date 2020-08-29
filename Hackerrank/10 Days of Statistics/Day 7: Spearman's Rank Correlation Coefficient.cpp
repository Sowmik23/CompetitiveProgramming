#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	
	vector<double> x, y, sortedX, sortedY;
	for(int i=0;i<n;i++){
		double data ;
		cin>>data;
		x.push_back(data);
	}
	for(int i=0;i<n;i++){
		double data ;
		cin>>data;
		y.push_back(data);
	}
	
	sortedX = x;
	sortedY = y;
	
	sort(sortedX.begin(), sortedX.end());
	sort(sortedY.begin(), sortedY.end());
	
	double rankX, rankY, rankdiff=0.0;
	for(int i=0;i<n;i++){
		vector<double>::iterator itX = find(sortedX.begin(), sortedX.end(), x[i]);
		vector<double>::iterator itY = find(sortedY.begin(), sortedY.end(), y[i]);
		
		rankX = distance(sortedX.begin(), itX);
		rankY = distance(sortedY.begin(), itY);
		
		rankdiff += pow((rankY-rankX), 2);
	}
	
	double correlationCoefficient = 1-((6*rankdiff)/(n*(n*n - 1)));
	
	cout<<setprecision(3)<<fixed<<correlationCoefficient<<endl;
	
	
	return 0;
}
