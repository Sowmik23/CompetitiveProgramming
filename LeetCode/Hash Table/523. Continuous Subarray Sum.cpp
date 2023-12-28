class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        // first try: using prefix sum: but maked it complex: failed
        /*
        int n = nums.size();
        long sum = 0;
        for(auto& n: nums) sum+=n;
        if(n==1) return false;

        if(sum%k==0) return true;
        if(sum<k) return false;

        vector<int> prefixSum(n, 0), suffixSum(n, 0);

        prefixSum[0]=0;
        suffixSum[n-1] = 0;
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1]+nums[i-1];
            suffixSum[n-i-1] = suffixSum[n-i] + nums[n-i];
        }
        // cout<<sum<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<i<<" "<<prefixSum[i]<<" "<<suffixSum[i]<<endl;
        // }
        for(int i=0;i<n-1;i++){
            long total1 = sum-prefixSum[i];
            if(total1%k==0) return true;

            total1 = sum-suffixSum[i+1];
            if(total1%k==0) return true;

            total1 = sum-prefixSum[i]-suffixSum[n-i-1];
            if(total1%k==0) return true;

            total1 = sum-suffixSum[i+1]-prefixSum[n-i-1];
            if(total1%k==0) return true;
        }

        return false;
        */

        //using hashmap: math actually: Lean more about remainder
        int sum = 0;
        unordered_map<int, int> mp{{0, 0}}; //// initialize the hash map with index 0 for sum 0
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(!mp.count(sum%k)){ //// if the remainder sum % k occurs for the first time
                mp[sum%k] = i+1;
            }
            else if(i>mp[sum%k]) return true;   //// if the subarray size is at least two
        }
        return false;
    }
};


//Test Cases:
// [23,2,4,6,7]
// 6
// [23,2,6,4,7] //5, 1, 1, 5, 0
// 6
// [23,2,6,4,7]
// 13
// [0]
// 1
// [0,0]
// 1
// [2,2]
// 4
// [1,3,6,0,9,6,9]
// 7
// [23,6,9]
// 6
