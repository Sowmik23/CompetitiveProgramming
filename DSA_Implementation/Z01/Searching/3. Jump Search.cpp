#include <bits/stdc++.h>
using namespace std;

//Time: O(sqrt(n))
//Auxiliary Space: O(1)

//Points:
/// Works only sorted arrays
/// Binary search is better than jump search. But jump search has an 
/// advantages that we traverse back only once, but in binary search require
/// up to logn jums

/// Consider a situation where we need to searched the smallest element.
/// So, in a system where binary search is costly, we use jump search.



int jumpSearch(vector<int> &nums, int target){
	
	int n = nums.size();
	int stepSize = sqrt(n);
	int prev = 0;
	
	while(nums[min(stepSize, n)-1] < target){
		prev = stepSize;
		stepSize+=sqrt(n);
		
		if(prev>=n) return -1;
	}
	while(nums[prev]<target){
		prev++;
		if(prev==min(stepSize, n)) return -1;
	}
	if(nums[prev]==target) return prev;
	
	return -1;
} 
	

int main(){
	
	vector<int> nums = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int target = 55;
	
	
	int res = jumpSearch(nums, target);
	if(res==-1) cout<<"Not found"<<endl;
	else cout<<"Found at position: "<<res<<endl;
	
	
	return 0;
}
