#include <bits/stdc++.h>
using namespace std;


//Time: O(nLogn)
//Auxiliary Space: O(n)


void merge(vector<int> &nums, int left, int mid, int right){
	int n1 = mid-left+1;
	int n2 = right-mid;

	vector<int> a(n1), b(n2);
	for(int i=0;i<n1;i++){
		a[i] = nums[left+i];
	}
	for(int i=0;i<n2;i++){
		b[i] = nums[mid+1+i];
	}
	
	int i=0, j=0, k=left;
	while(i<n1 and j<n2){
		if(a[i]<b[j]){
			nums[k++] = a[i++];
		}
		else {
			nums[k++] = b[j++];
		}
	}
	while(i<n1){
		nums[k++] = a[i++];
	}
	while(j<n2){
		nums[k++] = b[j++];
	}
}

void mergeSort(vector<int> &nums){
	int n = nums.size();
	int currSize;
	int leftStart;
	for(currSize=1;currSize<n;currSize*=2){
		for(leftStart=0;leftStart<n;leftStart+=(2*currSize)){
			int mid = min(leftStart+currSize-1, n-1);
			int rightEnd = min(leftStart+2*currSize-1, n-1);
			
			merge(nums, leftStart, mid, rightEnd);
		}
	}
}


int main(){
	
	vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	mergeSort(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
