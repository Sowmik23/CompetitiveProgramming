// 1297. Maximum Number of Occurrences of a Substring
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        
        int n = s.size();
        int res = 0;

        unordered_map<string, int> mp;
        vector<int> freq(26, 0);
        int left = 0, right = 0;
        int unique = 0;

        while(right<n){
            char ch = s[right];
            right++;
            freq[ch-'a']++;
            if(freq[ch-'a']==1) unique++;
            while(unique>maxLetters or right-left>minSize){
                freq[s[left]-'a']--;
                if(freq[s[left]-'a']==0) unique--;
                left++;
            }
            if(right-left==minSize){
                string str = s.substr(left, minSize); 
                mp[str]++;
                res = max(res, mp[str]);
            }
        }
        return res;
    }
};