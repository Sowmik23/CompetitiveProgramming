#include <bits/stdc++.h>
using namespace std;


/*
 * Selection Sort
 * Time: O(n^2) Best case: O(n^2)	
 * Space: O(1)
 * In-place: Yes
 * Stable: NO  //example: Given [2, 2, 1], the '2' values will not 
 * retain their initial order. Selection Sort is not stable because 
 * it swaps non-adjacent elements.
 * 
 * Selection sort can be made Stable if instead of swapping, 
 * the minimum element is placed in its position without swapping
 * i.e. by placing the number in its position by pushing every element
 * one step forward. In simple terms use a technique like insertion sort 
 * which means inserting element in its correct place.
 * 
 * Class: comparison sort
 */

vector<int> selectionSort(vector<int> &nums){
	
	for(int i=0;i<nums.size()-1;i++){
		int smallestIndex = i;
		for(int j=i+1;j<nums.size();j++){
			if(nums[smallestIndex]>nums[j]){
				smallestIndex = j;
			}
		}
		swap(nums[i], nums[smallestIndex]);
	}
	
	return nums;
}



int main(){
	
	vector<int> nums = {5, 4, 2, 7, 3, 1, 9, 8};
	
	nums = selectionSort(nums);
	
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
