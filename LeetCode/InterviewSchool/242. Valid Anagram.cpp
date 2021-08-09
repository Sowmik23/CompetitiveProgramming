class Solution {
public:
    bool isAnagram(string s, string t) {
        
        ///Approach: 01 : Time: nlogn, Space: O(1)
       /* sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        
        if(s==t) return true;
        else return false; */
        
        ///Approach: 02: Time : O(n), Space: O(n)
        unordered_map<char, int> mp;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<t.size();i++){
            if(mp[t[i]]<=0) return false;
            else {
                mp[t[i]]--;
            }
        }
        for(auto i: mp){
            if(i.second>0) return false;
        }
        return true;
    }
};
