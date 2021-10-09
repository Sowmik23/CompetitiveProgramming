#include <bits/stdc++.h>
using namespace std;


long long dp[3005][3005];


int calculate(int left, int right, long long sum, vector<long long > &nums) {
	
	if(left == right-1) return max(nums[left], nums[right]);
  
	if(dp[left][right]!=-1) return dp[left][right];
	
	dp[left][right]  = max( (sum - calculate(left+1, right, sum-nums[left], nums)), 
					(sum - calculate(left, right-1, sum-nums[right], nums)) );
	
	return dp[left][right];
}

int main(){
	
	int n;
	long long x;
	scanf("%d", &n);
	vector<long long> nums;
	for(int i=0;i<n;i++){
		scanf("%lld", &x);
		nums.push_back(x);
	}
	
	int l = 0;
	int r = n-1;
	
	memset(dp, -1, sizeof(dp));
	
	
	long long sum = 0;
	for(int i=0;i<=r;i++){
		sum+=nums[i];
	}
	
	long long rajib = calculate(l, r, sum, nums);
	
	//cout<<rajib<<" "<<sum-rajib<<endl;
	
	long long rakib = sum-rajib; 
	
	if(rajib>rakib)  cout<<rajib-rakib<<" "<<"Rajib"<<endl;
	else if(rajib<rakib) cout<<rakib-rajib<<" Rakib"<<endl;
	else cout<<rajib-rakib<<" Both Chocolates are same"<<endl;
	
	
	return 0;
}
