#include <bits/stdc++.h>
using namespace std;


//Time: O(n^2)
//Auxiliary Space: O(1)

//Worst case: when array is reversly sorted
//Best case: when array is already sorted

//In-Place: Yes
//Stable: Yes
//Class: Comparison based	

/// It works by repeatedly swapping adjacent elements.
/// It sorts from last towards first

/// It is used to introduce the concept of sorting algorithm


void BubbleSort(vector<int> &nums){
	for(int i=0;i<nums.size();i++){
		bool flag = false;
		for(int j=0;j<nums.size()-i-1;j++){
			if(nums[j]>nums[j+1]){
				flag = true;
				swap(nums[j], nums[j+1]);
			}
		}
		if(flag==false) break;
	}
}


int main(){
	
	vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
	BubbleSort(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
