#include <bits/stdc++.h>
using namespace std;


//Bucket sort is mainly useful when input is uniformly distributed over a range
/// Time Complexity	 
/// Best	O(n+k)
/// Worst	O(n2)
/// Average	O(n)
/// Space Complexity	O(n+k)
/// Stability	Yes


void bucketSort(vector<int> &nums){
	int mx=INT_MIN;
	
	for(int i=0;i<nums.size();i++){
		if(nums[i]>mx) mx = nums[i];
	}
	
	vector<int> bucket[nums.size()];
	 
	 ///put elements in different buckets
	for(int i=0;i<nums.size();i++){
		int bi = nums.size()*nums[i]/(mx+1); //index no in bucket
		bucket[bi].push_back(nums[i]);
	}
	
	///sort individual buckets
	for(int i=0;i<nums.size();i++){
		sort(bucket[i].begin(), bucket[i].end());
	}
	
	int index = 0;
	for(int i=0;i<nums.size();i++){
		for(int j=0;j<bucket[i].size();j++){
			nums[index++] = bucket[i][j];
		}
	}
	
}
	


int main(){

	vector<int> nums = { 5, 3, 2, 4, 1, 7};

	bucketSort(nums);
	
	for(auto i: nums) cout<<i<<" ";
	cout<<endl;
	

	return 0;
}
