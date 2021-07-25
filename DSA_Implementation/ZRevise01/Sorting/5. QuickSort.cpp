#include <bits/stdc++.h>
using namespace std;

/*
 * Quick Sort
 * Time: O(n*logn) : Best & Average : Worst: O(n^2)
 * Space: O(1): But it is listed as space complexity is: O(logn)
 * Stable: No
 * In-place: Yes
 * Class: Comparison
 * Method: partitioning
 */

int partition(vector<int> &nums, int l, int r){
	int partitionIdx = l;
	int pivot = nums[r];
	
	for(int i=l;i<r;i++){
		if(nums[i]<=pivot){
			swap(nums[i], nums[partitionIdx]);
			partitionIdx++;
		}
	}
	swap(nums[partitionIdx], nums[r]);
	return partitionIdx;
}

void QuickSort(vector<int> &nums, int l, int r){
	
	if(l<r){
		int pivotIdx = partition(nums, l, r);
		
		QuickSort(nums, l, pivotIdx-1);
		QuickSort(nums, pivotIdx+1, r);
	}
} 


int main(){
	
	vector<int> nums = {5, 4, 2, 7, 3, 1, 9, 8};
	
	int l = 0, r = nums.size()-1;
	QuickSort(nums, l, r);
	
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
