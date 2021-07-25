#include <bits/stdc++.h>
using namespace std;


int lower_bound(vector<int> nums, int l, int r, int val){
	int mid;
	int low = l, high = r;
	
	while(low<high){
		mid = (low+high)/2;
		
		if(nums[mid]>=val){
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	
	if(low < r and nums[low]<val){
		low++;
	}
	
	return low;
}


int upper_bound(vector<int> nums, int l, int r, int val){
	
	int mid;
	int low = l, high = r;
	
	while(low<high){
		mid = (low+high)/2;
		
		if(nums[mid]>val){
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	if(low<r and nums[low]<=val){
		low++;
	}
	return low;
}

int main(){
	
	vector<int> nums = {65, 43, 21, 54, 21, 25, 78, 98, 43,  32, 17};
	
	sort(nums.begin(), nums.end());
	
	
	int  k = lower_bound(nums, 0, nums.size(), 25);
	cout<<k<<endl;
	
	
	return 0;
}
