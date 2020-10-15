#include <bits/stdc++.h>
using namespace std;

double c;

double checkSqrt(double k){
	double l = 0, h = 9e20, mid;
	for(int i=0;i<100;i++){
		mid = (l+h)/2.0;
		if(mid*mid>=k) h = mid;
		else l = mid;
	}
	return mid;
} 
		
		

bool good(double mid){
	double k = mid*mid + checkSqrt(mid);
	
	return k>=c;
}


int main(){
	
	cin>>c;
	
	double low = 0, high = 9e20, mid;
	for(int i=0;i<100;i++){
		mid = (low+high)/2.0;
		
		if(good(mid)) high = mid;
		else low = mid;
	}
	//cout<<low<<" "<<mid<<" "<<high<<endl;
	cout<<setprecision(20)<<fixed<<high<<endl;
	
	
	return 0;
}
