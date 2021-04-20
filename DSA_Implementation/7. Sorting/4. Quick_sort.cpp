#include <bits/stdc++.h>
using namespace std;


int partition(int *nums, int start, int end){
	int pivot = nums[end];
	int partitionIdx = start;
	for(int i=start;i<end;i++){
		if(nums[i]<=pivot){
			//swap
			swap(nums[i], nums[partitionIdx]);
			partitionIdx++;
		}
	}
	//swap 
	swap(nums[partitionIdx], nums[end]);
	return partitionIdx;
}


void quick_sort(int *nums, int start, int end){
	if(start<end) {
		int pivotIdx = partition(nums, start, end);
		
		quick_sort(nums, start, pivotIdx-1);
		quick_sort(nums, pivotIdx+1, end);
	}
}


int main(){
	
	int nums[] = { 4, 6, 2,1, 6, 4,3,2,5};
	
	//calculate size of nums array
	int n = sizeof(nums)/sizeof(nums[0]);
	//int n = *(&nums + 1) - nums;
	cout<<n<<endl;
	
	quick_sort(nums, 0, n-1);
	
	for(auto i: nums){
		cout<<i<<" ";
	}
	cout<<endl;
	
	return 0;
}
