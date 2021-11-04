#include <bits/stdc++.h>
using namespace std;


// Time: O(nlogn)
// Auxiliary Space: O(n)

// In-Place: No
// Stable: Yes
// Class: Comparison based
// Divide and Conquer algorithm


//Drawbacks:
/// Takes extra memory
/// It goes through the whole process even if the array is sorted


void merge(vector<int> &nums, int left, int mid, int right){
	int n1 = mid-left+1;
	int n2 = right -mid;
	
	vector<int> a(n1), b(n2);
	for(int i=0;i<n1;i++){
		a[i] = nums[left+i];
	}
	for(int i=0;i<n2;i++){
		b[i] = nums[mid+1+i];
	}
	
	int i=0, j = 0, k = left;
	
	while(i<n1 and j<n2){
		if(a[i]<b[j]){
			nums[k] = a[i];
			i++;
		}
		else {
			nums[k] = b[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		nums[k++] = a[i++];
	}
	while(j<n2){
		nums[k++] = b[j++];
	}
}


void mergeSort(vector<int> &nums, int left, int right){
	if(left<right){
		int mid = left+(right-left)/2;
		
		mergeSort(nums, left, mid);
		mergeSort(nums, mid+1, right);
		
		merge(nums, left, mid, right);
	}
}


int main(){
	
	vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	mergeSort(nums, 0, nums.size()-1);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
