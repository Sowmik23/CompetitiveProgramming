#include <bits/stdc++.h>
using namespace std;


/*
 * Quickselect is a textbook algorthm typically used to solve the
 * problems "find kth something": kth smallest, kth largest, 
 * kth most frequent, kth less frequent, etc. Like quicksort, 
 * quickselect was developed by Tony Hoare, and also known as 
 * Hoare's selection algorithm.
 * 
 * It has \mathcal{O}(N)O(N) average time complexity and widely 
 * used in practice. It worth to note that its worth case time 
 * complexity is \mathcal{O}(N^2)O(N 2 ), 
 * although the probability of this worst-case is negligible.
 *
 * The approach is the same as for quicksort.
*/



int partition(vector<int> &nums, int l, int r){
	
	int pivot = nums[r];
	int partitionIdx = l;
	
	for(int i=l;i<=r-1;i++){
		if(nums[i]< pivot){
			swap(nums[i], nums[partitionIdx]);
			partitionIdx++;
		}
	}
	swap(nums[partitionIdx], nums[r]);
	
	return partitionIdx;
}


int quickSelect(vector<int> &nums, int l, int r, int k){
	
	if(l<=r) {
		int pivotIndex = partition(nums, l, r);

		//cout<<k<<" "<<pivotIndex<<" "<<l<<" "<<r<<endl;
		//for(auto i: nums) cout<<i<<" ";
		//cout<<endl;
		
		if(pivotIndex==k){
			return nums[pivotIndex];
		}
		else if(pivotIndex>k){
			return quickSelect(nums, l, pivotIndex-1, k);
		}
		else {
			return quickSelect(nums, pivotIndex+1, r, k);
		}
	}
	
	//return INT_MAX; //if k is more than number of elements in nums array
}


int main(){
	
	vector<int> nums = {3,2,1,5,6,4};
	
	int k = 5;
	//ans will be 5 : kth largest
	
	int d = quickSelect(nums, 0, nums.size()-1, nums.size()-k);
	
	//cout<<d<<" kdfk " <<endl;
	
	cout<<k<<"th largest number is: "<<nums[nums.size()-k]<<endl;

	
	cout<<k<<"th smallest number is: "<<quickSelect(nums, 0, nums.size()-1, k)<<endl;
	
	
	
	return 0;
}
