class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        //-4 -1 1 2//-4, -3,  2,

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int closestSum = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int currSum = nums[i]+nums[j]+nums[k];
                if(currSum==target) return currSum;

                if(abs(target-currSum)<abs(target-closestSum)){
                    closestSum = currSum;
                }
                if(currSum>target) k--;
                else j++;
            }
        }

        return closestSum;
    }
};
