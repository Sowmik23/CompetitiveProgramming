// 1799. Maximize Score After N Operations
class Solution {
public:
    int maxScore(vector<int>& nums) {
        
        int memoSize = 1<<nums.size();
        vector<int> memo(memoSize, -1);

        return backTrack(nums, 0, 0, memo);
    }
private:
    int backTrack(vector<int> &nums, int mask, int takenPair, vector<int> &memo){

        //if picked all nums from nums
        if(2*takenPair==nums.size()) return 0;

        //if already solved
        if(memo[mask]!=-1) return memo[mask];

        int mxScore = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                //if numbers are same or already picked
                if(((mask>>i)&1)==1 or ((mask>>j)&1)==1) continue;

                //mark both nums as picked
                int newMask = mask | (1<<i) | (1<<j);

                int currScore = (takenPair+1)*__gcd(nums[i], nums[j]);
                int remainScore = backTrack(nums, newMask, takenPair+1, memo); 
                mxScore = max(mxScore, currScore+remainScore);
            }
        }
        memo[mask] = mxScore;
        return mxScore;
    }
};