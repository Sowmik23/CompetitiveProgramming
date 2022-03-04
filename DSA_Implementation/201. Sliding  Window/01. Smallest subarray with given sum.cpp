#include <bits/stdc++.h>
using namespace std;

///Find the smallest window which window has greater 
///or equal of given sum
///Ex. 4 2 2 7 8 1 2 8 1 0 and and given sum = 8 and ans will be 1


int lengthofSmallestSubarray(vector<int>nums, int targetSum){
	
	int minWindowLen = INT_MAX;
	int currentwindowSum = 0, left = 0, right = 0;
	
	while(right<nums.size()){
		currentwindowSum+=nums[right];
		right++;
		
		while(currentwindowSum>=targetSum){
			minWindowLen = min(minWindowLen, right-left);
			currentwindowSum -=nums[left];
			left++;
		}
	}
	return minWindowLen; 
}



int main(){
	
	vector<int> nums = { 4, 2, 2, 7, 8, 1, 2, 8, 1, 0};
	
	int targetSum = 9;
	
	cout<<lengthofSmallestSubarray(nums, targetSum)<<endl;
	
	
	return 0;
}
