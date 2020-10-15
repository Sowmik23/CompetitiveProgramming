#include <bits/stdc++.h>
using namespace std;


/// Problem: https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
/// Category: Binary Search

typedef long long ll;

ll arr[100005];
int n, k;

bool binarySearch(ll x){
	int low = 0, high=n-1, mid;
	while(low<=high){
		mid = (low+high)/2;
		if(arr[mid]==x) return true;
		if(arr[mid]>x) high = mid-1;
		else if(arr[mid]<x) low = mid+1;
	}
	return false;
}


int main(){
	
	ll query;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	while(k--){
		cin>>query;
			
		if(binarySearch(query)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
