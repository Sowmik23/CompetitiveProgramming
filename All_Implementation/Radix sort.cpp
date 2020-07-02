#include <bits/stdc++.h>

using namespace std;

int getMax(int arr[], int n){
	int mx = arr[0];
	for(int i=0;i<n;i++){
		if(mx<arr[i]) mx = arr[i];
	}
	return mx;
}

void radixsort(int arr[], int n){
	
	int m = getMax(arr, n);
	cout<<m<<endl;
	
	for( int exp = 1; (m/exp)>0; exp*=10){
		int count[10] = {0};
		int out[n];
		
		for(int i=0;i<n;i++){
			count[(arr[i]/exp)%10]++;
		}
		for(int i=1;i<10;i++){
			count[i]+=count[i-1];
		}
		for(int i=n-1;i>=0;i--){
			out[count[(arr[i]/exp)%10] - 1]=arr[i];
			count[(arr[i]/exp)%10]--;
		}
		for(int i=0;i<n;i++){
			arr[i] = out[i];
		}
	}
	for(int i=0;i<n;i++) cout<<arr[i]<<" ";
	cout<<endl;
}


int main(){
	
/*
	8
	170 45 75 90 802 24 2 66
*/	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	radixsort(arr, n);
	
	return 0;
}
