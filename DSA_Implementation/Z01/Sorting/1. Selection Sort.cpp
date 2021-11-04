#include <bits/stdc++.h>
using namespace std;


// Time: O(n^2)
// Auxiliary Space: O(1)

// In-Place: Yes, it does not require extra space
// Stable: No (but can make it stable)
// Class: Comparison based

/// It sorts from the first position towards last

/// It never takes more than O(n) swaps. So it is useful when memory 
/// write is costly operation

	
//this is default implementation of selection sort
//and this default implementation is not stable

/// Definition of Stability: A sorting algorithm is said to be stable 
/// if two objects with equal or same keys appear in the same order in 
/// sorted output as they appear in the input array to be sorted.




///default implementation: Unstable
void SelectionSort(vector<int> &nums){
	for(int i=0;i<nums.size();i++){
		int minIdx = i;
		for(int j=i+1;j<nums.size();j++){
			if(nums[j]<nums[minIdx]){
				minIdx = j;
			}
		}
		swap(nums[i], nums[minIdx]);
	}
}


///Stable selection sort:(by modifying)
void SelectionSortStable(vector<int> &nums){
	for(int i=0;i<nums.size();i++){
		int minIdx = i;
		for(int j=i+1;j<nums.size();j++){
			if(nums[j]<nums[minIdx]){
				minIdx = j;
			}
		}
		int tmp = nums[minIdx];
		while(minIdx>i){
			nums[minIdx] = nums[minIdx-1];
			minIdx--;
		}
		nums[minIdx] = tmp;
	}
}


int main(){
	
	vector<int> nums = {64, 25, 12, 22, 11};
	
	//SelectionSort(nums);
	SelectionSortStable(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
