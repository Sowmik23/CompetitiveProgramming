#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	int arr[n];
	double sum = 0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	
	double mean = sum/n;
	//cout<<mean<<endl;
	
	sum = 0;
	for(int i=0;i<n;i++){
		sum+= ((arr[i] - mean)*(arr[i] - mean));
	}
	
	double standard_deviation = sqrt(sum/n);
	cout<<setprecision(1)<<fixed<<standard_deviation<<endl;
	
	return 0;
}
