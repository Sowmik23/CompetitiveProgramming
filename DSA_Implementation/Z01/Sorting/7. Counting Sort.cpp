#include <bits/stdc++.h>
using namespace std;


// Time: O(n+k) //k is range, n is total element
// Auxiliary Space: O(n+k)

// In-Place: No
// Stable: Yes, if we store in res from last index else no
// Class: Counting

//Point to be noted:
/// 1. Counting sort is efficient if the range of input is not 
///    significantly greater than the number of elements to be sorted
/// 2. It is often used as a sub-routing of radix sort
/// 3. It also works for negative inputs also


void CountingSort(vector<int> &nums){
	int mx = INT_MIN;
	int mn = INT_MAX;
	
	for(int i=0;i<nums.size();i++){
		mx = max(mx, nums[i]);
		mn = min(mn, nums[i]);
	}
	
	vector<int> cnt(mx-mn+1);
	for(int i=0;i<nums.size();i++){
		cnt[nums[i]-mn]++;
	}
	
	for(int i=1;i<cnt.size();i++){
		cnt[i]+=cnt[i-1];
	}
	
	vector<int> res(nums.size());
	for(int i=nums.size()-1;i>=0;i--){
		res[cnt[nums[i]-mn]-1] = nums[i];
		cnt[nums[i]-mn]--;
	}
	
	for(int i=0;i<nums.size();i++){
		nums[i] = res[i];
	}
}


int main(){
	
	vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	CountingSort(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
