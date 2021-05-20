class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
     
        
        ///approach-01: using another array: Complexity: Time: O(n),Memeory: O(n)
/*      vector<int> res(nums.size());
        
        int j =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                res[j]= nums[i];
                j+=2;
            }
        }
        
        j = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1) {
                res[j] = nums[i];
                j+=2;
            }    
        }
                    
        return res;
        */
        
        ///apporach-02: in place: Time: O(n), Memory: O(1)
        
        int j =1;
        for(int i=0;i<nums.size();i+=2){
            if(nums[i]%2==1){
                while(nums[j]%2==1 and j<nums.size()) j+=2;
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};
