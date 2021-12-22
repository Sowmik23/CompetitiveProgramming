class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(nums.size()==0) return {-1, -1};
        
        int x = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int y = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        
        //cout<<x<<" "<<y<<endl;
        
        if(x>=nums.size() or y-1>=nums.size() or nums[x]!=target) return {-1, -1};
        return  {x, y-1};
    }

};
