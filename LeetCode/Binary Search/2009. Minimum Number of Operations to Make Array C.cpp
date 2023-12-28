// 2009. Minimum Number of Operations to Make Array Continuous

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        //sorting + binary search
        //Time: O(n*logn)
        int n = nums.size();
        sort(nums.begin(), nums.end());


        //find the unique len[removing duplicate]
        int uniqueEleLen = 1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[uniqueEleLen] = nums[i];
                uniqueEleLen++;
            }
        }

        int res = n;
        int j = 0;

        for(int i = 0;i<uniqueEleLen;i++){
            while(j<uniqueEleLen and nums[j]-nums[i]<=n-1){
                j++;
            }
            res = min(res, n-(j-i));
        }
        return res;
    }
};