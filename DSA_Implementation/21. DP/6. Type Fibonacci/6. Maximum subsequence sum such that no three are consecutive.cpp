#include <bits/stdc++.h> 

int recursive(vector<int> &nums, int i){
	if(i<0) return 0;
	if(i==0) return nums[0];

	//taking current and next consecutive elements but skipping the third
	int a = nums[i]+nums[i-1]+recursive(nums, i-3);

	//skipping current element
	int b = recursive(nums, i-1);

	//taking current but not taking next element
	int c = nums[i]+recursive(nums, i-2);

	return max({a, b, c});
}

int recursionWithMemo(vector<int> &nums, vector<int> &memo, int i){
	if(i<0) return 0;
	if(i==0) return nums[0];

	if(memo[i]!=-1) return memo[i];

	//taking first two consecutive elements
	int a = nums[i]+nums[i-1]+recursionWithMemo(nums, memo, i-3);

	//skipping current element
	int b = recursionWithMemo(nums, memo, i-1);

	//taking current but skipping current next
	int c = nums[i]+recursionWithMemo(nums, memo, i-2);

	return memo[i] = max({a, b, c});
}

int maxSum(vector<int> &nums, int n) 
{
	
	//recursive
	//return recursive(nums, nums.size()-1);

	//recursive with memoization
	vector<int> memo(nums.size(), -1);
	return recursionWithMemo(nums, memo, nums.size()-1);


	int sum[n];   

    if(n>=1)  sum[0] = nums[0];   
    if(n>=2)  sum[1] = nums[0] + nums[1];    
    if(n>2)   sum[2] = max(sum[1], max(nums[1]+nums[2],nums[0]+nums[2]));        
    for(int i=3; i<n; i++){        
        sum[i] = max(max(sum[i-1],sum[i-2]+nums[i]), nums[i]+nums[i-1]+sum[i-3]);    
    }    
    return sum[n-1];
}
