class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      
        //Time: O(n), Space: O(n)
        /*
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        
        prefix[0] = 1;
        suffix[nums.size()-1] = 1;
        
        for(int i=1;i<nums.size();i++){
            
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        
        for(int i=0;i<nums.size();i++){
           // cout<<prefix[i]<<" "<<suffix[i]<<endl;
            nums[i] = prefix[i]*suffix[i];
        }
        
        return nums;
        */
        
        ///Without using extra Space: Time: O(n), Space: O(1)
        vector<int> res(nums.size());
        
        res[0] = 1;
        for(int i=1;i<nums.size();i++){
            res[i] = res[i-1]*nums[i-1];
        }
        
       // for(int i=0;i<nums.size();i++) cout<<res[i]<<" ";
        
        int tmp = 1;
        for(int i=nums.size()-2;i>=0;i--){
            res[i] *= tmp*nums[i+1];
            tmp *= nums[i+1];
        }
        
        return res;
    }
};
