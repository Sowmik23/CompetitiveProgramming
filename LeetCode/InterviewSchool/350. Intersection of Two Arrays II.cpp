///Approach-01: Sorting and memory efficient
//Time: nlogn
//Memory: O(n) / O(1)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> res;
        int i = 0, j= 0;
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]>nums2[j]) j++;
            else {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return res;
    }
};

///Approach-02: using map but it is memory inefficient
//Time: O(n)
//Memory:O(n)
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
