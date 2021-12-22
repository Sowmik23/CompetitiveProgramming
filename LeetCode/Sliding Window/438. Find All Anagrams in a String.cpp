class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(p.size()>s.size()) return {};
        vector<int> res;
        
        unordered_map<char, int> mp;
        for(auto& ch: p){
            mp[ch]++;
        }
        
        
        int left = 0, right = 0;
        
        while(right<s.size()){
            if(mp[s[right]]>0){ 
                mp[s[right]]--;
                right++;
                
                if(right-left==p.size()){
                    res.push_back(left);    
                }
            }
            else if(left==right){
                left++;
                right++;
            }
            else {
                mp[s[left]]++;
                left++;
            }
        }
        
        
        return res;
    }
};
