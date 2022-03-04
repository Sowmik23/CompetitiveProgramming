#include <bits/stdc++.h>
using namespace std;


/// Binary Index Tree/Fenwick Tree: Better than Segment tree due to less 
/// memory requirement and a little faster than segment tree.
/// Time Complexity:

/// Query Time: O(logn)
/// Update Time: O(logn)


vector<int> bit;


int getSum(int index){
	int sum = 0;
	index = index+1;
	
	while(index>0){
		sum+=bit[index];
		
		index -=index&(-index);
	}
	
	return sum;
}


int getRangeSum(int l, int r){
	
	return getSum(r)-getSum(l-1);
}


void updateBIT(int index, int val, int n){
	index = index + 1;
	
	while(index<=n){
		bit[index] +=val;
		index += index&(-index);
	}
}


void constructBIT(vector<int> &nums){
	
	bit.assign(nums.size()+1, 0);
	int n = nums.size();
	
	for(int i=0;i<n;i++){
		updateBIT(i, nums[i], n);
	}
	
	///contents of bit 
	///for(int i=1;i<=n;i++) cout<<bit[i]<<" ";
}


int main(){
	
	vector<int> nums = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	
	constructBIT(nums);
	
	//get sum 0 to 5 index 
	cout<<getSum(5)<<endl; //ans is : 12
		
	//get sum l to r
	cout<<getRangeSum(5, 6)<<endl; //ans is : 7
	
	//index, value, n
	updateBIT(0, 9, nums.size());
	
	//get sum 0 to 5 index 
	cout<<getSum(5)<<endl; //ans is : 21
		
	
	return 0;
}
