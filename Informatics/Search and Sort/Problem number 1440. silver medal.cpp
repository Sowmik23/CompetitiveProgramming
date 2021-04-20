#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int n, mx = INT_MIN, secondMx=INT_MIN;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0;i<n;i++){
		if(arr[i]>mx){
			secondMx = mx;
			mx = arr[i];
		}
		else if(arr[i]> secondMx && arr[i]<mx){
			secondMx = arr[i];
		}
	}
	
	printf("First Max: %d\nSecond Max: %d\n", mx, secondMx);
	
	
	//5 4 3 7 8 9 1
	//4 3 3 1 2
	
	
	
	return 0;
}
