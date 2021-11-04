#include <bits/stdc++.h>
using namespace std;


// Time: O(nlogn)

// We we use tail call elimination
// Thus we can reduce worst case Space O(n^2) to O(logn)

// N.B: Merge sort is not tail recursive


// partition process is same


int partitionLast(vector<int> &nums, int left, int right){
	int val=nums[right];
	int partitionIdx = left;
	
	for(int i=left;i<right;i++){
		if(nums[i]<val){
			swap(nums[i], nums[partitionIdx]);
			partitionIdx++;
		}
	}
	swap(nums[right], nums[partitionIdx]);
	
	return partitionIdx;
}

void quickSortIterative(vector<int> &nums, int left, int right){
	
	int stack[right-left+1];
	
	int top = -1;
	stack[++top] = left;
	stack[++top] = right;


	while(top>=0){
		right = stack[top--];
		left = stack[top--];
		
		int pivot = partitionLast(nums, left, right);
		
		if(pivot-1>left) {
			stack[++top] = left;
			stack[++top] = pivot-1;
		}
		if(pivot+1<right){
			stack[++top] = pivot+1;
			stack[++top] = right;
		}
	}
}


int main(){
	
	vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	quickSortIterative(nums, 0, nums.size()-1);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
