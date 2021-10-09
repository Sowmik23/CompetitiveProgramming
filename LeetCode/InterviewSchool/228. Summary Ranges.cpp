class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> res;
        if(nums.size()==0) return res;
        
        int i=0;
        
        while(i<nums.size()){
         
            int start = i, end = i;
            
            while(end+1<nums.size() and nums[end]+1==nums[end+1]) end++;
            
            if(end>start) res.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            else if(start==end) res.push_back(to_string(nums[start]));
            i = end+1;
        }
        
        return res;
    }
};
