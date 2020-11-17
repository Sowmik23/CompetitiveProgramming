#include <bits/stdc++.h>
using namespace std;


/// Sliding window approach
/// Time Complexity O(n)

int maxSum(int arr[], int n, int k){
	int mx=0;
	for(int i=0;i<k;i++){
		mx+=arr[i];
	}
	
	int window_sum=mx;
	for(int i=k;i<n;i++){
		window_sum +=arr[i] - arr[i-k];
		mx = max(mx, window_sum);
	}
	return mx;
}


int main(){
	
	int n, k;
	scanf("%d%d", &n, &k);
	int arr[n+3];
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	cout<<maxSum(arr, n, k)<<endl;
	
	
	return 0;
}
