#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	int arr[n], freq[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int sm = 0;
	for(int i=0;i<n;i++){
		cin>>freq[i];
		sm+=freq[i];
	}
	int S[sm];
	
	int i = 0;
	for(int j=0;j<n;j++){
		for(int k=0;k<freq[j];k++){
			S[i++] = arr[j];
		}
	}
	n = sm;
	sort(S, S+n);
	//for(int j=0;j<n;j++) cout<<S[j]<<" ";
	//cout<<endl;
	
	double lower_Q = (S[n/4] + S[(n/2-1)/2])/2.0;
	double upper_Q = (S[(n+1)/2 + (n-(n+1)/2)/2] + S[(n+1)/2 + (n-(n+1)/2-1)/2])/2.0;
	//cout<<lower_Q<<" "<<upper_Q<<endl;
	
	cout<<setprecision(1)<<fixed<<(upper_Q - lower_Q)<<endl;
	
	return 0;
}
