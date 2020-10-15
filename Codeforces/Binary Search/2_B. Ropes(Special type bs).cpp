#include <bits/stdc++.h>
using namespace std;

/// problem: https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
/// B. Ropes
///There are n ropes, you need to cut k pieces of the same length from them.
/// Find the maximum length of pieces you can get.


typedef long long ll;
ll n, k, arr[10005];


bool good(double x){
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=floor(arr[i]/x);
	}
	return cnt>=k;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	double low=0, high=1e8, mid;
	
	for(int i=0;i<100;i++){
		
		mid = (low+high)/2.0;
	
		if(good(mid)) {
			low = mid;
		}
		else high = mid;
	}
	
	//cout<<low<<" "<<mid<<" "<<high<<endl;
	cout<<setprecision(20)<<fixed<<low<<endl;
	
	
	return 0;
}

