// Longest Increasing Subsequence

#include <bits/stdc++.h>
using namespace std;

//Time: O(2^n)
int recursive(vector<int> &nums, int idx, int prev, int n){
    if(idx==n) return 0;
    
    int taken = 0, notTaken = 0;
    if(prev==-1 or nums[idx]>nums[prev]){
        taken = 1+recursive(nums, idx+1, idx, n);
    }
    notTaken = recursive(nums, idx+1, prev, n);
    return max(taken, notTaken);
}


//Time: O(n^2)
int recursionWithMemo(vector<int> &nums, vector<vector<int>> &memo, int idx, int prev, int n){
    if(idx==n) return 0;
    if(memo[idx][prev+1]!=-1) return memo[idx][prev+1];
    
    int taken = 0, notTaken = 0;
    if(prev==-1 or nums[idx]>nums[prev]){
        taken = 1+recursionWithMemo(nums, memo, idx+1, idx, n);
    }
    notTaken = recursionWithMemo(nums, memo, idx+1, prev, n);
    memo[idx][prev+1] = max(taken, notTaken);
    return memo[idx][prev+1];
}

int recursionWithMemoization(vector<int> &nums, vector<int> &sortedNums, vector<vector<int>> &memo, int i, int j){
    if(i>=nums.size() or j>=sortedNums.size()) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    
    int taken = 0, notTaken = 0;
    if(nums[i]==sortedNums[j]){
        taken = 1+recursionWithMemoization(nums, sortedNums, memo, i+1, j+1);
    }
    notTaken = max(recursionWithMemoization(nums, sortedNums, memo, i+1, j), recursionWithMemoization(nums, sortedNums, memo, i, j+1));
    return memo[i][j] = max(taken, notTaken);
}

int _lcs(vector<int> &nums, vector<int> &sortedNums){
    
    int n = nums.size();
    
    vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
    return recursionWithMemoization(nums, sortedNums, memo, 0, 0);
}

int _lis(vector<int> &nums){
    int n = nums.size();
    
    //recursive
    return recursive(nums, 0, -1, n);
    
    //recursion with memoization
    vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
    return recursionWithMemo(nums, memo, 0, -1, n);
    
    //tabulation
    //Time: O(n^2)
    */
    vector<int> lis(n);
    lis[0] = 1;
    for(int i=1;i<n;i++){
        lis[i] = 1;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] and lis[i]<lis[j]+1){
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis.begin(), lis.end());
    */
    
    /*
    we can convert this problem to longest Common Subsequence(LCS) Problem. 
    Firstly we will create another array of unique elements of original array and sort it. 
    Now the longest increasing subsequence of our array must be present as a subsequence in our sorted array. 
    That’s why our problem is now reduced to finding the common subsequence between the two arrays.
    */
    */
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    
    return _lcs(nums, sortedNums);
    */

    //O(nlogn) solution
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


int main()
{
    vector<int> nums = {50, 3, 10, 7, 40, 80};
    cout<<"Lenght of longest increasing subsequence: "<<_lis(nums)<<endl; //4
    nums = {3, 10, 2, 1, 20};
    cout<<"Lenght of longest increasing subsequence: "<<_lis(nums)<<endl; //3
     nums = {3, 2};
    cout<<"Lenght of longest increasing subsequence: "<<_lis(nums)<<endl; //1
     nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout<<"Lenght of longest increasing subsequence: "<<_lis(nums)<<endl; //6
    
    return 0;
}


