// 1371. Find the Longest Substring Containing Vowels in Even Counts
class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        int mx = 0;
        unordered_map<int, int> mp;
        int curr = 0;
        mp[0] = -1;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                curr ^= 1<<(s[i]-'a');
                if(mp.find(curr)==mp.end()) mp[curr] = i;
            }
            mx = max(mx, i-mp[curr]);
        }
        return mx;
    }
};