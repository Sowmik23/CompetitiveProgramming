#include <bits/stdc++.h>
using namespace std;


// Time: O(n^2);
// Auxiliary Space: O(1)

// In-Place: Yes
// Stable: Yes
// Class: Comparison based
// Online: Yes. (Always keeps sorted from starting to current position)
// Incremental approach

/// Usage: When number of elements is small. and when elements are mostly
/// sorted and few elements are misplaced.


//Q.A: What is Binary Insertion Sort? 


void InsertionSort(vector<int> &nums){
	for(int i=1;i<nums.size();i++){
		
		int val = nums[i];
		int minIdx = i-1;
		while(minIdx>=0 and nums[minIdx]>val){
			nums[minIdx+1] = nums[minIdx];
			minIdx--;
		}
		nums[minIdx+1] = val;
	}
}


int main(){
	
	vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
	InsertionSort(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
