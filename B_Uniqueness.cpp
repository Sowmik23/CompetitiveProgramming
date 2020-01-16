#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	sort(arr,arr+n);
	
	int flag =0;
	int low=0, high=0 ;
	
	for(int i=0;i<n;i++){
		if(arr[i]==arr[i+1]){
			if(flag==0){
				 low = i+1;
				 flag = 1;
			 }
			high = upper_bound(arr, arr+n, arr[i+1]) - arr; 
		}
	}
	
	if(high>=n) high = n-1;
	else if(high>0) high--;

	//printf("%d %d\n",low,high);
	
	printf("%d\n",high-low);
		
	
	return 0;
}
