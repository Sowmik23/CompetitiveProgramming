class Solution {
public:
    int pivotIndex(vector<int>& nums) {

      //prefix sum
        int sum = 0;
        for(auto& n: nums) sum+=n;

        int left = 0;
        for(int i=0;i<nums.size();i++){
            if(sum-left-nums[i]==left) return i;
            left+=nums[i];
        }

        return -1;
    }
};
