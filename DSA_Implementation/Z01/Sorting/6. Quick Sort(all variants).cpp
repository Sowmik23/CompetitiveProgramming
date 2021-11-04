#include <bits/stdc++.h>
using namespace std;


// Time: O(nlogn)
// Auxiliary Space: O(1), but in recursive implementation it takes
// O(logn) space for recursion stack.

// For two recursive calls to itself and in worst case it 
// requires O(n) space on function call stack. 

/// Worst Case: O(n^2) : it occurs when the partition process always 
/// picks greatest or smallest element as pivot. 

///Best case: when partition process always picks the middle element

// Stable: No, but any sorting algorithm can be made stable by considering
// indexes as comparison parameter.

// In-place: Yes
// Class: Comparison
// Method: Partitioning

// Divide and Conquer algorithm(like merge sort)


// Q.A: Why MergeSort is preferred over QuickSort for Linked Lists? 


// Q.A: How to optimize QuickSort so that it takes O(Log n) extra
// space in worst case?


/// A small trick is that if you can implement only partition by last
/// element than for others just swap the element with last element
/// and do partition as last. 


// when pivot is the last element
int partitionRight(vector<int> &nums, int left, int right){
	int pivotIdx = left;
	int val = nums[right];
	
	for(int i=left;i<right;i++){
		if(nums[i]<=val){
			swap(nums[i], nums[pivotIdx]);
			pivotIdx++;
		}
	}
	swap(nums[right], nums[pivotIdx]);
	
	return pivotIdx;
}

//when pivot is the first element
int partitionFirst(vector<int> &nums, int left, int right){
	int val = nums[left];
	int partitionIdx = left+1;
	
	for(int i=left+1;i<=right;i++){
		if(nums[i]<=val){
			if(i!=partitionIdx) swap(nums[i], nums[partitionIdx]);
			partitionIdx++;
		}
	}
	swap(nums[left], nums[partitionIdx-1]);
	
	return partitionIdx-1;
}	
	

//when pivot is the middle element
int partitionMiddle(vector<int> &nums, int left, int right){
	int mid = left+(right-left)/2;
	int val = nums[mid];
	
	int i=left, j=right;
	while(i<=j){
		while(nums[i]<val) i++;
		while(nums[j]>val) j--;
		if(i<=j) {
			swap(nums[i], nums[j]);
			i++;
			j--;
		}
	}
	
	return i;
}
		
//when pivot is random element
int partitionRandom(vector<int> &nums, int left, int right){
	
	int index = rand()%(right-left)+left;
	//int val = nums[index];
	
	swap(nums[index], nums[right]);
	return partitionRight(nums, left, right);
}


void quickSort(vector<int> &nums, int left, int right){
	if(left<right){
		
		///partition last
		//int pivot = partitionRight(nums, left, right);
		//quickSort(nums, left, pivot-1);
		//quickSort(nums, pivot+1, right);
		
		///partition first
		//int pivot = partitionFirst(nums, left, right);
		//quickSort(nums, left, pivot-1);
		//quickSort(nums, pivot+1, right);
		
		///partition middle
		//int pivot = partitionMiddle(nums, left, right);
		//if(left<pivot-1) quickSort(nums, left, pivot-1);
		//if(pivot<right) quickSort(nums, pivot, right);
		
		///partition random
		int pivot = partitionRandom(nums, left, right);
		quickSort(nums, left, pivot-1);
		quickSort(nums, pivot+1, right);
	}
}



int main(){
	
	vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	quickSort(nums, 0, nums.size()-1);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
