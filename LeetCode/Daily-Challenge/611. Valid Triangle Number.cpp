class Solution {
public:
    int triangleNumber(vector<int>& nums) {
     
        //Condition of triangle: Sum of any two sides should be greater than the third side
        
        sort(nums.begin(), nums.end());
        
        
        int ans = 0;
        for(int i=2;i<nums.size();i++){
            
            int start = 0, end = i-1;
            int val = nums[i];
            
            while(start<end){
                if(nums[start] + nums[end] > val){
                    ans += end-start;
                    end--;
                }    
                else start++;
            }
        }
        
        
        return ans;
    }
};
