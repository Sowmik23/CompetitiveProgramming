#include <bits/stdc++.h>
using namespace std;


/// Sliding Window approach using deque
/// Time complexity O(n)


int minofmax(int arr[], int n, int k){
	int mn = 1e7;
	
	deque<int> dq(k);
	int i;
	for(i=0;i<k;i++){
		while( (!dq.empty()) and arr[dq.back()]<=arr[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	
	for( ;i<n;i++){
		//cout<<arr[dq.front()]<<endl;
		mn = min(mn, arr[dq.front()]);
		
		while( (!dq.empty()) and dq.front()<=i-k){
			dq.pop_front();
		}
		while( (!dq.empty()) and arr[dq.back()]<=arr[i]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	//cout<<arr[dq.front()]<<endl;
	mn = min(mn, arr[dq.front()]);
	return mn;
}


int main(){
	
	int n, query;
	scanf("%d%d", &n, &query);
	int arr[n+2];
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	
	int x;
	while(query--){
		scanf("%d", &x);
		
		int d = minofmax(arr, n, x);
		
		printf("%d\n", d);
	}
	
	
	return 0;
}
