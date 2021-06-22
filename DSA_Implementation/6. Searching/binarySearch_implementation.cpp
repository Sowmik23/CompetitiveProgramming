#include <bits/stdc++.h>
using namespace std;

/*
 * Time: O(logn)
 * Space: O(n)
 */

///iterative
int binarySearch(vector<int> nums, int l, int r, int val){
	int left = l, right = r, mid;
	while(left<=right){
		mid = (left+right)/2;
		if(nums[mid]==val) return mid;
		
		else if(nums[mid]>val) right = mid-1;
		else left = mid+1;
	}
	return -1;
}

///recursive
int binarySearchR(vector<int> nums, int l, int r, int val){
	if(l<=r){
		int mid = (l+r)/2;
		
		if(nums[mid]==val) return mid;
		else if(nums[mid]>val) return binarySearchR(nums, l, mid-1, val);
		else return binarySearchR(nums, mid+1, r, val);
	}
	return -1;
}



int main(){
	
	vector<int> nums = {3, 5, 7, 43,2, 6, 2, 6, 6, 89};
	
	sort(nums.begin(), nums.end());
	
	//int k = binarySearch(nums, 0, nums.size()-1, 6);
	
	int k = binarySearchR(nums, 0, nums.size()-1, 632);
	
	if(k==-1) cout<<"Value not found!"<<endl;
	else cout<<"Found at index: "<<k<<endl;
	
	return 0;
}
