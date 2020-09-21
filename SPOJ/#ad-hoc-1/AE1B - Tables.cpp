#include <bits/stdc++.h>
using namespace std;



int main(){
	
	int n, k, s;
	cin>>n>>k>>s;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	int total = k*s;
	//sort in decending order
	sort(arr, arr+n, greater<int> ());
	
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(total>0){
			cnt++;
			total= total - arr[i];
		}
	}
	cout<<cnt<<endl;
	
	return 0;
}


