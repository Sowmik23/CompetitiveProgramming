#include <bits/stdc++.h>
using namespace std;


//DP-1: Overlapping Subproblem property: 
//		- Memoization(Top Down)
//		- Tabulation(Bottom Up)


//DP-2: Optimal Substructure Property:
//		- A problem has optimal substructure property if optimal solution
//		- of the given problem can be obtained by using optimal 
//		- solutions of its subproblems




//DP-3: Longest Increasing Subsequence
/// Follow up: Can you come up with an algorithm that runs 
/// in O(n log(n)) time complexity?

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        //recursive:
        //return recursiveLIS(nums, -1, 0);
        
        
        //recursion with memoization
        //vector<vector<int>> memo(nums.size()+1, vector<int> (nums.size()+1, -1));
        //return recursionWithMemoizationLIS(nums, memo, -1, 0);
        
        
        //tabulation: TODO
        //Time: O(n^2)
        //Space: O(n)
        
        /*
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(nums[j]<nums[i]){
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
		
		int res = 0;
		for(int i=0;i<n;i++){
			res = max(res, dp[i]);
		}
		
		return res;
        */
        
        
        
        //How can you print the longest increasing list also?
       /* 
        int n = nums.size();
        vector<int> dp(n, 1), p(n, -1);
        
        for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				if(nums[j]<nums[i] and dp[i]<1+dp[j]){
					dp[i] = 1+dp[j];
					p[i] = j;
				}
			}
		}
        
        int res = 0;
        int pos = 0;
        for(int i=0;i<dp.size();i++){
			if(res<dp[i]){
				res = dp[i];
				pos = i;
			}
		}
        
        vector<int> lisList;
        while(pos!=-1){
			lisList.push_back(nums[pos]);
			pos = p[pos];
		}
        
        cout<<"longest length is: "<<res<<endl;
        for(auto& i: lisList) cout<<i<<" ";
        cout<<endl;
        
        reverse(lisList.begin(), lisList.end());
        */
        
        //FollowUP Solution(Using Binary Search): Time: NlogN
        //This approach is also called patience sorting
        
        int n = nums.size();
        vector<int> tmp;
        tmp.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(nums[i]>tmp.back()){
                tmp.push_back(nums[i]);
            } 
            else {
                int low = lower_bound(tmp.begin(), tmp.end(), nums[i])-tmp.begin();
                //cout<<low<<" "<<nums[i]<<endl;
                tmp[low] = nums[i];
            }
        }
        
        return tmp.size();
        
        
        
        //TODO: Longest increasing subsequence for linked list
        
        
    }
private:
    int recursiveLIS(vector<int> &nums, int prev, int curr){
        if(curr>=nums.size()) return 0;
        
        int take = 0;
        int notTake = 0;
        if(prev==-1 or nums[prev]<nums[curr]){
            take = 1+recursiveLIS(nums, curr, curr+1);
        }
        notTake = recursiveLIS(nums, prev, curr+1);
        
        return max(take, notTake);
    }
    
    int recursionWithMemoizationLIS(vector<int> &nums, vector<vector<int>> &memo, int prev, int curr){
        if(curr>=nums.size()) return 0;
        
        if(memo[prev+1][curr]!=-1) return memo[prev+1][curr];
        
        int x = 0;
        int y = 0;
        if(prev==-1 or nums[prev]<nums[curr]){
            x = 1+recursionWithMemoizationLIS(nums, memo, curr, curr+1);
        }
        y = recursionWithMemoizationLIS(nums, memo, prev, curr+1);
        
        return memo[prev+1][curr] = max(x, y);
    }
};



//FollowUP:
// binary search: O(nlogn)
public class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        int size = 0;
        
        for(int num: nums) {
            // binary search
            int left = 0, right = size, middle = 0;     // right = size
            while(left < right) {
                middle = left + (right - left) / 2;
                if(dp[middle] < num) left = middle + 1;
                else right = middle;
            }
            
            // left is the right position to 'replace' in dp array
            dp[left] = num;
            if(left == size) size++;
        }
        return size;
    }
}


int main(){
	
	vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	
//DP-3: Longest Increasing Subsequence
	//cout<<LCS(nums)<<endl;
	
	
	return 0;
}
