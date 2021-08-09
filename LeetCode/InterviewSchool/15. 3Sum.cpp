class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        ///Approach: 01 :Two pointers: Time: O(nlogn)
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();i++){
            
            if(i>0 and nums[i]==nums[i-1]) continue;
            
            int left = i+1;
            int right = nums.size()-1;
            
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum<0) left++;
                else if(sum>0) right--;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    while(left+1<right and nums[left]==nums[left+1]) left++;
                    while(left<right-1 and nums[right]==nums[right-1]) right--;
                    
                    left++;
                    right--;
                }
            }
        }
        
        return res;
    }
};
