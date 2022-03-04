#include <bits/stdc++.h>
using namespace std;

///Time Complexity: O(n)


int maxSum(vector<int> nums, int k){
	
	int sum =0;
	for(int i=0;i<k;i++){
		sum+=nums[i];
	}

	int window_sum = sum;
	for(int i=k;i<nums.size();i++){
		window_sum+= nums[i] - nums[i-k];
		if(window_sum>sum) sum = window_sum;
	}
	
	return sum;
}


int main(){
	
	vector<int> v = {1, 4, 2, 10, 2, 3, 1, 0, 20};
	
	int k = 4;
	cout<<maxSum(v, k)<<endl;
	
	
	return 0;
}
