class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     
        map<int, int> mp;
        vector<int> res;
        
        if(nums1.size()>nums2.size()){
            for(int i=0;i<nums1.size();i++){
                mp[nums1[i]] += 1;
            }
            
            for(int i=0;i<nums2.size();i++) {
                if(mp[nums2[i]]>=1) {
                    res.push_back(nums2[i]);
                    mp[nums2[i]]--;
                }
            }
        }
        else {
            for(int i=0;i<nums2.size();i++){
                mp[nums2[i]] += 1;
            }
            
            for(int i=0;i<nums1.size();i++) {
                if(mp[nums1[i]]>=1){
                  res.push_back(nums1[i]);
                    mp[nums1[i]]--;
                } 
            }
        }
                
        return res;
    }
};
