class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        // interesting 
        // sort the array and find the median then do operation
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n/2];
        
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans+= abs(nums[i]-median);
        }
        
        return ans;
    }
};
