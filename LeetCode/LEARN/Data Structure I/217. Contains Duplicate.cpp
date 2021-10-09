class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        ///Approach-01: using vector for counting frequency of each number
        //Disclaimer: in this case we need to remember that cnt arry index won't be negative in case of if nums contains negative values . So we need to find min number and negate it from all nums values etc..... 
       /*
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(auto& i: nums){
            mx = max(mx, i);
            mn = min(mn, i);
        }
       
        vector<int> cnt(mx-mn+1);
        
        for(int i=0;i<nums.size();i++){
            cnt[nums[i]-mn]++;
            if(cnt[nums[i]-mn]>=2) return true;
        }
        
        return false;
        */
        
        ///Approach-02: using set
      /*  unordered_set<int> st;
        
        for(auto& num: nums){
            if(st.count(num)) return true;
            else {
                st.insert(num);
            }
        }
        return false;
        */
        
        ///Approachh-03: using map
        unordered_map<int, int> mp;
        for(auto& num: nums){
            mp[num]++;
            if(mp[num]>=2) return true;
        }
        return false;
    }
};
