#include <bits/stdc++.h>
using namespace std;

// **********Amazing Problem ************
// *********Nice Solution *************
/*
 * Given an integer array A[] of size N. 
 * The task is to find the maximum of the minimum of 
 * every window size in the array.
 * 
 * Note: Window size varies from 1 to n.
*/

void solve(int arr[], int n){
	stack<int> stk;
	int left[n+2], right[n+2];
	
	for(int i=0;i<n;i++){
		left[i] = -1;
		right[i] = n;
	}
	
	//left part of the array
	for(int i=0;i<n;i++){
		while(!stk.empty() and arr[stk.top()]>=arr[i]) {
			stk.pop();
		}
		
		if(!stk.empty()){
			left[i] = stk.top();
		}
		
		stk.push(i);
	}
	
	while(!stk.empty()){
		stk.pop();
	}
	
	//right part of the array
	for(int i=n-1;i>=0;i--){
		while(!stk.empty() and arr[stk.top()]>=arr[i]){
			stk.pop();
		}
		
		if(!stk.empty()){
			right[i] = stk.top();
		}
		
		stk.push(i);
	}
	
	int ans[n+2];
	for(int i=0;i<=n;i++){
		ans[i] = 0;
	}
	for(int i=0;i<n;i++){
		int len = right[i] - left[i] - 1;
		ans[len] = max(ans[len], arr[i]);
	}
	
	for(int i=n-1;i>=1;i--){
		ans[i] = max(ans[i], ans[i+1]);
	}
	
	for(int i=1;i<=n;i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}



int main(){
	
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int arr[n+3];
		for(int i=0;i<n;i++) scanf("%d", &arr[i]);
		
		solve(arr, n);
		
	}
	
	
	return 0;
}
