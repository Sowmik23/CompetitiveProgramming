#include <bits/stdc++.h>
using namespace std;

/*
 * Counting Sort: It also works for negative numbers, for this we need 
 * to determine min number and subtract it with all others
 * 
 * Time: O(n+k) : (Best, worst, average same) k is range of elements
 * Space : O(max range)
 * Stable : Yes
 * Class: Non-comparison sort
 * In-place:  No (it use extra memory)
 */


void CountingSort(vector<int> &nums){
	//calculate max and min
	int mx = INT_MIN, mn = INT_MAX;
	for(int i=0;i<nums.size();i++){
		mx = max(mx, nums[i]);
		mn = min(mn, nums[i]);
	}
	
	int range = mx-mn+1;
	vector<int> cnt(range);
	
	vector<int> sortedNums(nums.size());
	
	//calculate frequency of each elements
	for(int i=0;i<nums.size();i++){
		cnt[nums[i]-mn]++; ///here by subtracting mn so that negative numbers will not affected
	}
	
	//calculate sum count
	for(int i=1;i<cnt.size();i++){
		cnt[i] +=cnt[i-1];
	}
	
	for(int i=nums.size()-1;i>=0;i--){
		sortedNums[cnt[nums[i]-mn]-1] = nums[i];
		cnt[nums[i]-mn]--;
	}
	
	for(int i=0;i<nums.size();i++){
		nums[i]= sortedNums[i];
	}
}


int main(){
	
	vector<int> nums = {5, 4, 2, -7, 7, -3, 1, 9, 8, -7, 2, 4, 6, 1};
	
	
	CountingSort(nums);
	
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
