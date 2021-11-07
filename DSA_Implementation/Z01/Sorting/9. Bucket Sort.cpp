#include <bits/stdc++.h>
using namespace std;


// Time: O(n+k), Best, Average: O(n), Worst(O^2)
// Memory: O(n+k)

// In-Place: No
// Stable: Yes
// Class: Comparison based

// Bucket sort is useful when input is uniformly distributed 
// over a range.

// To sort negative numbers using bucket sort we need to split
// the array into two parts: one is for only negative numbers*-1 
// and the other array is for positive number
// then sort them individually using bucket sort then merge them
// Done!


void BucketSort(vector<int> &nums){
	int mx = INT_MIN;
	
	for(int i=0;i<nums.size();i++){
		mx = max(mx, nums[i]);
	}
	
	vector<int> buckets[nums.size()];
	
	//put elements in different buckets
	for(int i=0;i<nums.size();i++){
		int bi = (nums.size()*nums[i])/(mx+1);
		buckets[bi].push_back(nums[i]);
	}
	
	//sort individual bucket
	for(int i=0;i<nums.size();i++){
		sort(buckets[i].begin(), buckets[i].end());
	}
	
	//merge all the bucket in one array
	int index = 0;
	for(int i=0;i<nums.size();i++){
		for(int j=0;j<buckets[i].size();j++){
			nums[index++] = buckets[i][j];
		}
	}
}


int main(){
	
	vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	BucketSort(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
