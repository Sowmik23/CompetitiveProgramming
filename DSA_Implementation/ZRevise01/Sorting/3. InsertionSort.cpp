#include <bits/stdc++.h>
using namespace std;


/*
 * Insertion Sort
 * Time: O(n^2) , Best case: O(n)
 * Space: O(1)
 * In-pace : yes
 * Stable: yes
 * Online: yes
 * Class: comparison 
 */


vector<int> insertionSort(vector<int> nums){
	
	for(int i=1;i<nums.size();i++){
		int hole = i;
		int value = nums[i];
		while(hole>0 and nums[hole-1]>value){
			nums[hole] = nums[hole-1];
			hole--;
		}
		nums[hole] = value;
	}
	
	return nums;
}


int main(){
	
	vector<int> nums = {5, 4, 2, 7, 3, 1, 9, 8};
	
	nums = insertionSort(nums);
	
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
