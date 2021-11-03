#include <bits/stdc++.h>
using namespace std;

//Time: O(logn)
//Auxiliary Space: O(1) 
/// recursive binary search requires logn stack space
/// iterative binary search requires O(1) space;


//Advantages of Exponential Search:
/// Exponential search is useful for unbounded search, where size of
/// array is infinite.

/// It works better than binary search for bounded arrays, when the 
/// element to be searched is closer to the first element.



int binarySearch(vector<int> &nums, int l, int r, int target){
	while(l<=r){
		int mid = l+(r-l)/2;
		if(nums[mid]==target) return mid;
		if(nums[mid]>target) r = mid;
		else l = mid+1;
	}
	return -1;
}


int exponentialSearch(vector<int> &nums, int target){
	
	if(nums[0]==target) return 0;
	
	int n = nums.size();
	int i = 1;
	while(i<n and nums[i]<=target){
		i = i*2;
	}
	int left = i/2;
	int right = min(i, n-1);
	
	return binarySearch(nums, left, right, target);
}


int main(){
	
	vector<int> nums = {2, 3, 4, 10, 40};
	int target = 10;
	
	int res = exponentialSearch(nums, target);
	if(res==-1) cout<<"Not found"<<endl;
	else cout<<"Found at position: "<<res<<endl;
	
	
	return 0;
}
