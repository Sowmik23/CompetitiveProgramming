class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        
        int left=0, right = 0;
        
        map<int, int> mp;
        int mx = 0;
        int sum = 0;
        
        ///[1,2,5,2,1,2,5]
        ///[4,2,4,5,6]

        
        while(right<nums.size()){
            mp[nums[right]]++;
            sum+=nums[right];
            
            while(mp[nums[right]]>1){
                sum-=nums[left];
                mp[nums[left]]--;
                left++;
            }
            mx = max(mx, sum);
            
            right++;
        }
      
        
        return mx;
    }
};
