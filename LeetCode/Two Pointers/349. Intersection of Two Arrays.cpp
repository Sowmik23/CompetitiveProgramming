class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
      /*  map<int, int> mp;
        set<int> st;
        for(int i=0;i<nums1.size();i++){

            mp[nums1[i]] = 1;    
        }
        
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]==1) st.insert(nums2[i]);
        }
        
        vector<int> res(st.size());
        copy(st.begin(), st.end(), res.begin());
        
        return res;
        */
        
        ///another way
        
        set<int> st1;
        set<int> st2;
        
        for(int i=0;i<nums1.size();i++){
            st1.insert(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++){
            if(st1.find(nums2[i])!=st1.end()) st2.insert(nums2[i]);
        }
        
        vector<int> res(st2.size());
        copy(st2.begin(), st2.end(), res.begin());
        
        return res;
    }
};
