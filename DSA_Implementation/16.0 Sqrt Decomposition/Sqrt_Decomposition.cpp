#include <bits/stdc++.h>
using namespace std;


// Problem: Range Sum Query
/// Rang minimum, Range GCD etc.

/// Preprocessing: Time: O(n)
/// Query: Time: O(sqrt(n))
/// Point Update: Time: O(1)

// Time: O(sqrt(n))
// Space: O(sqrt(n))

#define MAX_N 1000

vector<int> block(MAX_N, 0);
int blkSize;

//Time: O(n)
void preprocess(vector<int> &nums){

	int n = nums.size();
	blkSize = sqrt(n);
	int blk_index = -1;
	
	for(int i=0;i<n;i++){
		if(i%blkSize==0){
			blk_index++;
		}
		block[blk_index]+=nums[i];
	}
}

//Time: O(sqrt(n))
int query(vector<int> &nums, int left, int right){
	int sum = 0;
	//first part
	while(left<right and left%blkSize!=0){
		sum+=nums[left];
		left++;
	}
	//middle
	while(left + blkSize<=right){
		sum+=block[left/blkSize];
		left+=blkSize;
	}
	//last part
	while(left<=right){
		sum+=nums[left];
		left++;
	}
	
	return sum;
}

//Update index value(Point update): Time: O(1)
void update(vector<int> &nums, int index, int val){
	block[index/blkSize] +=val-nums[index];
	nums[index] = val;
}

int main(){
	
	vector<int> nums = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
	
	//pre-process first
	preprocess(nums);
	
	//then query
	cout<<query(nums, 3, 8)<<endl;
	cout<<query(nums, 0, 6)<<endl;
	
	update(nums, 0, 10);
	
	for(auto& i: nums){
		cout<<i<<" ";
	}
	cout<<endl;
	
	cout<<query(nums, 0, 6)<<endl;
	
	return 0;
}
