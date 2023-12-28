class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        for(auto& i: nums) sum+=i;
        target = sum-target;
        if(target%2) return 0;

        return recursive(nums, target/2, 0, nums.size());
    }
private:
    int recursive(vector<int> &nums, int target, int sum, int i){
        if(sum==target and i==0) return 1;
        if(i==0) return 0;

        int taken = 0, notTaken = 0;
        if(sum+nums[i-1]<=target) taken+=recursive(nums, target, sum+nums[i-1], i-1);
        notTaken += recursive(nums, target, sum,  i-1);
        return taken+notTaken;
    }
};
