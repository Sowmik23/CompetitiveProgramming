#include <bits/stdc++.h>
using namespace std;




int slidingWindow(int arr[], int n, int k){

	deque<int> dq1(k), dq2(k);
	int i;
	
	for(i=0;i<k;i++){
		//for max
		while( (!dq1.empty()) and arr[dq1.back()]<= arr[i]){
			dq1.pop_back();
		}
		dq1.push_back(i);
		//for min
		while( (!dq2.empty()) and arr[dq2.back()]>= arr[i]){
			dq2.pop_back();
		}
		dq2.push_back(i);
	}
	
	int sum = 0;
	for( ; i<n;i++){
		
		//for finding max
		int mx = arr[dq1.front()];
		//cout<<mx<<" ";
		while( (!dq1.empty()) and dq1.front()<=i-k){
			dq1.pop_front();
		}
		while( (!dq1.empty()) and arr[dq1.back()]<=arr[i]){
			dq1.pop_back();
		}
		dq1.push_back(i);
		
		//for finding min
		int mn = arr[dq2.front()];
		cout<<mn<<endl;
		while((!dq2.empty()) and dq2.front()<=i-k){
			dq2.pop_front();
		}
		while((!dq2.empty()) and arr[dq2.back()]>=arr[i]){
			dq2.pop_back();
		}
		dq2.push_back(i);
		
		sum+=mx+mn;
	} 	
	//cout<<arr[dq1.front()]<<" "<<arr[dq2.front()]<<endl;
	sum+=arr[dq1.front()] + arr[dq2.front()];
	
	return sum;
}
	

int main(){
	
	int n, k;
	scanf("%d%d", &n, &k);
	
	int arr[n+5];
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	
	
	int d = slidingWindow(arr, n, k);
	
	printf("%d\n", d);
	
	return 0;
}
