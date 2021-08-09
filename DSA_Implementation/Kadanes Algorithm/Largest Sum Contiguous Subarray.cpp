#include <bits/stdc++.h>
using namespace std;

///Kadane's Algorithm: 
/// Finding largest sum of contigouos subarray

int maxSubArraySum(vector<int> &nums){
	int sum = 0;
	int maxSum = INT_MIN;
	
	for(int i=0;i<nums.size();i++){
		sum+=nums[i];
		if(maxSum<sum){
			maxSum = sum;
		}
		if(sum<0) sum = 0;
	}
	
	return maxSum;
}


int main(){
	
	vector<int> nums = { -2, -3, 4, -1, -2, 1, 5, -3};
	
	cout<<maxSubArraySum(nums)<<endl;
	
	return 0;
}
