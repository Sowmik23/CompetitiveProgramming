#include <bits/stdc++.h>
using namespace std;


// Time: O(n^2)

// We can use binary search to reduce the number of comparisons in 
// normal insertion sort, So it reduce O(n) comparison to O(logn)



int binarySearch(vector<int> &nums, int l, int r, int target){
	while(l<r){
		int mid = l+(r-l)/2;
		if(nums[mid]>target) r = mid;
		else {
			l = mid+1;
		}
	}
	if(l<nums.size() and nums[l]<=target) l++;
	return l;
}


void InsertionSort(vector<int> &nums){
	for(int i=1;i<nums.size();i++){
		int val = nums[i];
		int minIdx = i-1;
		
		int Idx = binarySearch(nums, 0, minIdx, val);
		while(minIdx>=Idx){
			nums[minIdx+1] = nums[minIdx];
			minIdx--;
		}
		nums[minIdx+1] = val;
	}
}	


int main(){
	
	vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	InsertionSort(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
