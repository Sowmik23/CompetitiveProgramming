

************** Topics *******************

1. MCM
2. Printing MCM
3. Evaluate expression to true / boolean parenthesization
4. Minimum or maximum value of a expression
5. Palindrome partitioning
6. Scramble string
7. Super Egg Drop
8. Burst Ballons





// Problem Statement- Given a sequence of matrices, find the most efficient way to multiply these matrices together.
// The efficient way is the one that involves the least number of multiplications.
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        vector<int> nums;
        for(int i=0;i<n;i++){
            nums.push_back(arr[i]);
        }

        //recursive
        // return recursive(nums, 1, n-1);

        //recursion with memoization
        // vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
        // return recursionWithMemo(nums, memo, 1, n-1);

        //tabulation
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int i=n-2;i>0;i--){
            for(int j=i+1;j<n;j++){
                int ans = INT_MAX;
                for(int k=i;k<j;k++){
                    int tmp = dp[i][k] + dp[k+1][j] + (nums[i-1]*nums[k]*nums[j]);
                    ans = min(ans, tmp);
                }
                dp[i][j] = dp[j][i] = ans;
            }
        }
        return dp[1][n-1];
    }
private:
    int recursive(vector<int> &nums, int i, int j){
        if(i>=j) return 0;

        int res = INT_MAX;
        for(int k=i;k<j;k++){
            int tmp = recursive(nums, i, k) + recursive(nums, k+1, j) + (nums[i-1]*nums[k]*nums[j]);
            res = min(res, tmp);
        }
        return res;
    }
    int recursionWithMemo(vector<int> &nums, vector<vector<int>> &memo, int i, int j){
        if(i>=j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        int res = INT_MAX;
        for(int k=i;k<j;k++){
            int tmp = recursionWithMemo(nums, memo, i, k) + recursionWithMemo(nums, memo, k+1, j) + (nums[i-1]*nums[k]*nums[j]);
            res = min(res, tmp);
        }
        return memo[i][j] = res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
