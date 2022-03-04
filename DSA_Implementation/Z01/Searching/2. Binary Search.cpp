#include <bits/stdc++.h>
using namespace std;


//Time: O(logn)

//Auxiliary Space: O(1) for iterative implementation
// 	and O(logn) for recursive implementation for recursion call stack space 


//Q. A: Why it contains bug if we calculate mid = (low+high)/2 ? instead //integer overflow : if high==INT_MAX
// mid = low+(high-low)/2 ?


//iterative version
int binarySearch(vector<int> &nums, int target){
	
	int left =0, right = nums.size()-1;
	int mid;
	
	while(left<=right){
		mid = left+(right-left)/2;
		if(nums[mid]==target) return mid;
		if(nums[mid]>target) right = mid;
		else left = mid+1;
	}
	return -1;
}

//recursive version
int binarySearchRecursive(vector<int> &nums, int left, int right, int target){
	
	if(left<=right){
		int mid = left+(right-left)/2;
		
		if(nums[mid]==target) return mid;
		if(nums[mid]>target) return binarySearchRecursive(nums, left, mid-1, target);
		return binarySearchRecursive(nums, mid+1, right, target);
	}
	
	return -1;
}



int main(){
	
	vector<int> nums = { 2, 3, 4, 10, 40 };
	int target = 10;
	
	int res = binarySearch(nums, target);
	if(res==-1) cout<<"Not found"<<endl;
	else cout<<"Found at position: "<<res<<endl;
	
	res = binarySearchRecursive(nums, 0, nums.size()-1, target);
	if(res==-1) cout<<"Not found"<<endl;
	else cout<<"Found at position: "<<res<<endl;
	
	
	return 0;
}
