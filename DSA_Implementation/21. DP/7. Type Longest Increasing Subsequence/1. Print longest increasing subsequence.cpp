// 1. Print longest increasing subsequence.cpp

//O(nlogn) solution
//FollowUP Solution(Using Binary Search): Time: NlogN
   
int longestStringIncreasingList(vector<int> &nums){
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

    //print the longest strictly increasing list
    for(auto& num: tmp) cout<<num<<" ";
    cout<<endl;
    
    return tmp.size();
}

// Other solutions using dp: Leetcode-300: 300. Longest Increasing Subsequence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        //recursive:
        //return recursiveLIS(nums, -1, 0);
        
        
        //recursion with memoization
        //vector<vector<int>> memo(nums.size()+1, vector<int> (nums.size()+1, -1));
        //return recursionWithMemoizationLIS(nums, memo, -1, 0);
        
        
        //tabulation: TODO
        /*int n = nums.size();
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
        
        //print the list also
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
        
        
        return res;
        */
        
        //FollowUP Solution(Using Binary Search): Time: NlogN
        
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