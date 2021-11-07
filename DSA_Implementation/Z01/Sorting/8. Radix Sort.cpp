#include <bits/stdc++.h>
using namespace std;

// What is the running time of Radix Sort? 
// O(d*(n+b))

/// b = base of the number
/// d = max length of number
/// n = total number


// Time: O(N*d) ==O(N)
// Auxiliary Space: O(N)



/// The lower bound for Comparison based sorting algorithm
/// (Merge Sort, Heap Sort, Quick-Sort .. etc) is Ω(nLogn)
/// they cannot do better than nLogn

// What if the elements are in the range from 1 to n^2? 
/// We can’t use counting sort because counting sort will 
/// take O(n^2) which is worse than comparison-based sorting 
/// algorithms. 
// Can we sort such an array in linear time? 

/// Yes, Radix sort is the answer. Digit by digit sorting
/// from least significant digit to most significant digit.


void CountingSort(vector<int> &nums, int exp){
	
	vector<int> cnt(10);
	for(int i=0;i<nums.size();i++){
		cnt[(nums[i]/exp)%10]++;
	}
	
	for(int i=1;i<10;i++){
		cnt[i]+=cnt[i-1];
	}
	
	vector<int> res(nums.size());
	
	for(int i=nums.size()-1;i>=0;i--){
		res[cnt[(nums[i]/exp)%10]-1] = nums[i];
		cnt[(nums[i]/exp)%10]--;
	}
	
	for(int i=0;i<nums.size();i++){
		nums[i] = res[i];
	}
}


void RadixSort(vector<int> &nums){
	
	int mx = INT_MIN;
	for(int i=0;i<nums.size();i++){
		mx = max(mx, nums[i]);
	}
	
	for(int exp=1;mx/exp>0;exp*=10){
		CountingSort(nums, exp);
	}
}


int main(){
	
	vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	RadixSort(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
