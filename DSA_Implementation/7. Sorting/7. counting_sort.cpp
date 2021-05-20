#include <bits/stdc++.h>
using namespace std;


/// Time Complexity	 : n=number of elements , K: range of elements
/// Best	O(n+k)
/// Worst	O(n+k)
/// Average	O(n+k)
/// Space Complexity	O(maxRange)
/// Stability	Yes

//it works for negative numbers as well
void countingSort(vector<int> &nums){
	
	///calculate max, min 
	int mx = INT_MIN, mn = INT_MAX;
	for(int i=0;i<nums.size();i++){
		mx = max(mx, nums[i]);
		mn = min(mn, nums[i]);
	}

	int range = mx-mn+1;
	vector<int> sortedNums(nums.size());
	vector<int> cnt(range); 
	
	///calculate frequency of each elements
	for(int i=0;i<nums.size();i++){
		cnt[nums[i]-mn]++;
	}
	
	///calculate sum count
	for(int i=1;i<cnt.size();i++){
		cnt[i] += cnt[i-1];
	}
	
	for(int i=nums.size()-1;i>=0;i--){
		sortedNums[cnt[nums[i]-mn]-1] = nums[i];
		cnt[nums[i]-mn]--;
	}
	
	for(int i=0;i<nums.size();i++){
		nums[i] = sortedNums[i];
	}
}



int main(){
	
	vector<int> nums = {5, -4, 3, 1, -2, 10, 6};
	
	countingSort(nums);
	
	
	for(auto i: nums) cout<<i<<" ";
	cout<<endl;
	
	
	return 0;
}
