#include <bits/stdc++.h>
using namespace std;

/*
 * Bubble sort
 * Time: O(n^2)
 * Space: O(1)
 * In-place: yes(extra memory use kore na)
 * Stable: yes(order thik thake)
 * class: comparison
 */



vector<int> bubbleSort(vector<int> &nums){

	for(int i=0;i<nums.size()-1;i++){
		bool flag = false;
		for(int j=0;j<nums.size()-i-1;j++){
			if(nums[j]>nums[j+1]){
				swap(nums[j], nums[j+1]);
				flag = true;
			}
		}
		if (flag==false) break;
	}
	
	return nums;
}


int main(){
	
	vector<int> nums = {5,4, 2,7, 3,2, 7,4};
	
	nums = bubbleSort(nums);
	
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
