#include <bits/stdc++.h>
using namespace std;



int main(){
	
	int n, k;
	scanf("%d%d", &n, &k);
	int arr[n+4];
	
	int mx=-1e9-5, mn=1e9+5;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);
	}
	
	
	if(k==1) {
		printf("%d\n", mn);
	}
	else if(k==2) {
		printf("%d\n", max(arr[0], arr[n-1]));
	}
	else {
		printf("%d\n", mx);
	}
	
	return 0;
}
