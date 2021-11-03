#include <bits/stdc++.h>
using namespace std;


//Time: O(n)
//Worst case: O(n)
//Q.A. How to decrease worst case time complexity O(n) to O(1) in linear search? ans: below

int linearSearch(vector<int> &nums, int target){
	for(int i=0;i<nums.size();i++){
		if(nums[i]==target) return i;
	}
	
	return -1;
}

//improved version of linear search
//just use two pointer to improve worst-case time complexity to O(N) to O(1)

int improvedLinearSearch(vector<int> &nums, int target){
	int left = 0;
	int right = nums.size()-1;
	
	while(left<=right){
		if(nums[left]==target) return left;
		if(nums[right]==target) return right;
		
		left++;
		right--;
	}
	
	return -1;
}


int main(){
	
	vector<int> nums = {4, 5, 7, 54, 3, 2, 5, 7, 2, 1};
	int target = 54;
	
	
	int res = linearSearch(nums, target);
	if(res==-1) cout<<"Not found"<<endl;
	else cout<<"Found at position: "<<res<<endl;
	
	
	res = improvedLinearSearch(nums, target);
	if(res==-1) cout<<"Not found"<<endl;
	else cout<<"Found at position: "<<res<<endl;
	
	
	return 0;
}
