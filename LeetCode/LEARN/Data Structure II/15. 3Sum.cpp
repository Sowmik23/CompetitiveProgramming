class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        
        //Time complexity: O(n^2)
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        
        for(int i=0;i<nums.size();i++){
            
            if(i>0 and nums[i]==nums[i-1]) continue;
            
            int left = i+1;
            int right = nums.size()-1;
            
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum>0) right--;
                else if(sum<0) left++;
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    while(left+1<right and nums[left]==nums[left+1]) left++;
                    while(left<right-1 and nums[right-1]==nums[right])  right--;
                    
                    left++;
                    right--;
                }
            }
        }
        
        return res;
    }
};
