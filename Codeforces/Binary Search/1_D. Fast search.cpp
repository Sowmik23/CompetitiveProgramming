#include <bits/stdc++.h>
using namespace std;


/// Problem: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
/// Category: Binary Search(How many numbers values are between l and r?)

typedef long long ll;

ll arr[200005];
int n, k;

int binarySearchClosestToRight(ll x){
	int low = 0, high=n-1, mid;
	int d = 0;

	while(low<=high){
		mid = (low+high)/2;
		
		if(arr[mid]==x) {
			d = mid;
			while(mid>0){
				mid = mid-1;
				if(arr[mid]!=x) break;
				d = mid; 
			}
			return d;
		}
		
		if(arr[mid]>x) high = mid-1;
		else if(arr[mid]<x) low = mid+1;
	}
	if(arr[mid]>x) return mid;
	if(arr[mid]<x) return mid+1;
}

int binarySearchClosestToLeft(ll x){
	int low = 0, high=n-1, mid;
	int d = 0;

	while(low<=high){
		mid = (low+high)/2;
		
		if(arr[mid]==x) {
			d = mid;
			while(mid<=n-1){
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
	
	ll l, r;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	sort(arr, arr+n);
	cin>>k;
	while(k--){
		cin>>l>>r;
			
		if(arr[0]==l and arr[n-1]==r) cout<<n<<" ";
		else {
			int right = binarySearchClosestToLeft(r);
			int left = binarySearchClosestToRight(l);
			
			cout<<right-left<<" ";
		}
		//cout<<right<<" "<<left<<endl;
	}
	
	return 0;
}


