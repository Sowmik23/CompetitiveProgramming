class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        unordered_map<char, int> mp;
        
        int left =0, right = 0, res = 0;
        
        while(right<s.size()){
            char c1 = s[right];
            mp[c1]++;
            right++;
            
            while(mp[c1]>1){
                char c2 = s[left];
                mp[c2]--;
                left++;
            }
            
            res =max(res, right-left);
        }
        
        
        return res;
    }
};
