class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        
        //Boyer-Moore Voting Algorithm: Time: O(n), Space: O(1)
        //finding majority element from an array
        int cnt = 0;
        int res;
        
        for(int i=0;i<nums.size();i++){
            
            if(cnt==0) res = nums[i];
            
            if(nums[i]==res){
                cnt+=1;
            }
            else  cnt -=1;
        }
        
        return res;
    }
};
