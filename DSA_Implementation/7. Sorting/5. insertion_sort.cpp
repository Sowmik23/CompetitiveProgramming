#include <bits/stdc++.h>

using namespace std;

///Insertion Sort
///Time Complexity: Base Case: O(n), Worst case: O(n^2), avg-case:O(n^2)


void insertionSort(vector<int> &nums){
	
	int value, hole;
	for(int i=1;i<nums.size();i++){
		value = nums[i];
		hole = i;
		while(hole>0 and nums[hole-1]>value){
			nums[hole] = nums[hole-1];
			hole--;
		}
		nums[hole] = value;
	}
}


int main(){
	
	vector<int> nums = { 5, 4, 3, 2, 1};
		
	insertionSort(nums);
	for(auto i: nums) cout<<i<<" ";
	cout<<endl;
	
	return 0;
}
