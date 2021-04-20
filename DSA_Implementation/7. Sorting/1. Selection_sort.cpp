#include <bits/stdc++.h>
using namespace std;


vector<int> selection_sort(vector<int> nums){
	int tmp, n = nums.size(), i, smallestValueIdx;
	for(i=0;i<n-1;i++){
		smallestValueIdx = i;
		for(int j=i+1;j<n;j++){
			if(nums[j]<nums[smallestValueIdx]){
				smallestValueIdx = j;
			}
		}
		//swap
		tmp = nums[i];
		nums[i] = nums[smallestValueIdx];
		nums[smallestValueIdx] = tmp; 
	}
	return nums;
}


int main(){
	
	vector<int> v;
	
	v = { 3, 4, 6,32,1, 4, 6,4,0};
	
	v = selection_sort(v);
	
	//here is the sorted array
	for(auto i: v){
		cout<<i<<" ";
	}
	cout<<endl;
	
	return 0;
}
