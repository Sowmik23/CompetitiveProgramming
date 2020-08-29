#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	sort(arr, arr+n);
	//for(int i=0;i<n;i++) cout<<arr[i]<< " ";
	int lower_Q, upper_Q, median;
	
	//cout<<n/2 + n/4<<" "<<n/2 + n/4 + 1<<endl;
	median = (arr[n/2] + arr[(n-1)/2])/2; 
	lower_Q = (arr[n/4] + arr[(n/2-1)/2])/2;
	upper_Q = (arr[(n+1)/2 + (n-(n+1)/2)/2] + arr[(n+1)/2 + (n-(n+1)/2-1)/2])/2;
	
	cout<<lower_Q<<endl;
	cout<<median<<endl;
	cout<<upper_Q<<endl;
	
	
	return 0;
}
