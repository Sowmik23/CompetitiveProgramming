#include <bits/stdc++.h>
using namespace std;

//Time: O(logn)
//Auxiliary space: O(1)


int upperBound(vector<int> &nums, int x){
	int low = 0, high = nums.size();
	
	while(low<high){
		int mid = low+(high-low)/2;
		if(nums[mid]>x){
			high = mid;
		}
		else {
			low = mid+1;
		}
	}
	if(low<nums.size() and nums[low]<=x) low++;
	
	return low;
}

int lowerBound(vector<int> &nums, int x){
	int low = 0, high = nums.size();
	
	while(low<high){
		int mid= low+(high-low)/2;
		if(nums[mid]>=x){
			high = mid;
		}
		else low = mid+1;
	}
	if(low<nums.size() and nums[low]<x) low++;
	
	return low;
}


int main(){
	
	vector<int> nums = {4, 6, 10, 12, 18, 20};
	
	int x = 6;
	cout<<"Upper Bound of "<<x<<" is: "<<upperBound(nums, x)<<endl;
	cout<<"Lower Bound of "<<x<<" is: "<<lowerBound(nums, x)<<endl;
	
	return 0;
}
