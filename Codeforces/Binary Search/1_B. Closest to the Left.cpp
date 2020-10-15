#include <bits/stdc++.h>
using namespace std;


/// Problem: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
/// Category: Binary Search

typedef long long ll;

ll arr[200005];
int n, k;

int binarySearch(ll x){
	int low = 0, high=n-1, mid;
	int d = 0;

	while(low<=high){
		mid = (low+high)/2;
		
		if(arr[mid]==x) {
			d = mid;
			while(1){
				mid = mid+1;
				if(arr[mid]!=x) break;
				d = mid; 
			}
			return d+1;
		}
		
		if(arr[mid]>x) high = mid-1;
		else if(arr[mid]<x) low = mid+1;
	}
	if(arr[mid]>x) return mid;
	if(arr[mid]<x) return mid+1;
}



int main(){
	
	ll query;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	while(k--){
		cin>>query;
			
		int ans = binarySearch(query);
		cout<<ans<<endl;
	}
	
	return 0;
}
