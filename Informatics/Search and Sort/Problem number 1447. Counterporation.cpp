#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int n;
	scanf("%d", &n);
	int arr[n];
	
	int mx = INT_MIN, mn = INT_MAX;
	
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		if(mx<arr[i]) mx = arr[i];
		if(mn>arr[i]) mn = arr[i];
	}
	
	for(int i=0;i<n;i++){
		if(arr[i]==mx){
			arr[i] = mn;
		}
	}
	
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	
	return 0;
}
