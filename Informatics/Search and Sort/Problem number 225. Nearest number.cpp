#include <bits/stdc++.h>


using namespace std;


int main(){
	
	int n, x;
	scanf("%d", &n);
	
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
		
	int diff, res;
	int ans = INT_MAX;
	scanf("%d", &x);
	for(int i=0;i<n;i++){
		if(x>arr[i]){
			diff = x-arr[i];
		}
		else diff = arr[i]-x;
		
		if(diff<ans) {
			ans = diff;
			res = arr[i];
		}
	}
	printf("%d\n", res);
	
	return 0;
}
