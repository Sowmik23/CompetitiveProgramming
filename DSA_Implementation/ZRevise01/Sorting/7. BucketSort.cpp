#include <bits/stdc++.h>
using namespace std;


/* Disclaimer: there is a bug for negative nmber in this code
 * Bucket Sort: It is mainly useful when input is uniformly distributed
 * over a range
 * 
 * Time: O(n+k): Best, Average: O(n), Worst: O(n^2)
 * Memory: O(n+k)
 * Stable: Yes
 * In-place: No
 * Class: comparison based
 */


void BucketSort(vector<int> &nums){
	
	int mx = INT_MIN;
	int mn = INT_MAX;
	for(int i=0;i<nums.size();i++){
		mx = max(mx, nums[i]);
		mn = min(mn, nums[i]);
	}
	
	vector<int> buckets[nums.size()];
	
	//put elements in different buckets
	for(int i=0;i<nums.size();i++){
		int bi = nums.size()*(nums[i]-mn)/(mx+1); ///index number in bucket
		buckets[bi].push_back(nums[i]);
	}
	
	//sort individual bucket
	for(int i=0;i<nums.size();i++){
		sort(buckets[i].begin(), buckets[i].end());
	}
	
	int index = 0;
	for(int i=0;i<nums.size();i++){
		for(int j=0;j<buckets[i].size();j++){
			nums[index++] = buckets[i][j];
		}
	}
}


int main(){
	
	vector<int> nums = { 5, 3, 2, 4, 1, 7};

	BucketSort(nums);
	
	for(auto i: nums) cout<<i<<" ";
	cout<<endl;
	
	return 0;
}
