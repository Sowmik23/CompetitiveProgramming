class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        ///Approach: using set
        if(nums.size()<2 or k==0) return false;
        
        unordered_set<int> st;
        
        for(int i=0;i<nums.size();i++){
            
            if(i>k) { //as the sliding window size increases than k so we need to delete the first element from set
                st.erase(nums[i-k-1]);
            }
            if(st.count(nums[i])) return true;  //if nums[i] already exists in the set
            
            st.insert(nums[i]);
        }
        
        return false;
    }
};
