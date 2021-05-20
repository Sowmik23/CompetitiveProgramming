#include <bits/stdc++.h>
using namespace std;

///Radix Sort
/// Time Complexity	 
/// Best	O(n+k)
/// Worst	O(n+k)
/// Average	O(n+k)
/// Space Complexity	O(max)
/// Stability	Yes



void countingSort(vector<int> &nums, int place){
	
	int max = 10; //as max 10 bucket 0---9
	
	vector<int> cnt(max);
	
	//counting frequency of each element
	for(int i=0;i<nums.size();i++){
		cnt[(nums[i]/place)%10]++;
	}
	
	//creating count sum 
	for(int i=1;i<cnt.size();i++){
		cnt[i] += cnt[i-1];
	}
	
	//place the elements in sorted order
	vector<int> sortedNums(nums.size());
	for(int i=nums.size()-1;i>=0;i--){
		sortedNums[cnt[(nums[i]/place)%10]-1] = nums[i];
		cnt[(nums[i]/place)%10]--;
	}
	
	for(int i=0;i<nums.size();i++){
		nums[i] = sortedNums[i];
	}
}


void radixSort(vector<int> &nums){
	
	///finding maximum number
	int mx = nums[0];
	for(int i=1;i<nums.size();i++){
		if(mx<nums[i]) mx = nums[i];
	}
	
	///applying counting sort to sort element based on place value
	for(int place = 1; mx/place>0; place*=10){
		countingSort(nums, place);
	}
}
	

int main(){
	
	vector<int> nums ={ 5, 4, 3, 7, 8, 54, 2, 1};
	radixSort(nums);
	
	for(auto i: nums) cout<<i<<" ";
	cout<<endl;
	
	
	
	return 0;
}
