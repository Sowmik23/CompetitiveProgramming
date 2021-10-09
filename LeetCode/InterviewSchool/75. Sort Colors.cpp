class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        ///Approach-01: using just three variable
        /*
        int redCount = 0, whiteCount = 0, blueCount = 0;
        
        for(auto& i: nums){
            if(i==0) redCount++;
            else if(i==1) whiteCount++;
            else if(i==2) blueCount++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(redCount>0){
                nums[i] = 0;
                redCount--;
            }
            else if(whiteCount>0){
                nums[i] = 1;
                whiteCount--;
            }
            else if(blueCount>0){
                nums[i] = 2;
                blueCount--;
            }
        }
        */
        
        //Approach-02: using counting sort
        
        int mx = INT_MIN, mn = INT_MAX;
        for(int i=0;i<nums.size();i++){
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        
        vector<int> cnt(mx-mn+1, 0);
        
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]-mn]++;
        }
        
        
        for(int i=1;i<cnt.size();i++){
            cnt[i] +=cnt[i-1];
        }
        
        vector<int> sortedNums(nums.size());
        
        for(int i=nums.size()-1;i>=0;i--){
            sortedNums[cnt[nums[i]-mn]-1] = nums[i];
            cnt[nums[i]-mn]--;
        }
        
        for(int i=0;i<nums.size();i++){
            nums[i] = sortedNums[i];
        }
        
    }
};              
