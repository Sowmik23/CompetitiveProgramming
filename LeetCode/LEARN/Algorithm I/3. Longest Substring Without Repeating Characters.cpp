class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> freq;
        
        int left = 0, right = 0;
        int mx = 0;
        
        while(right<s.size()){
            char c1 = s[right]; 
            freq[c1]++;
            right++;
            
            while(freq[c1]>=2){
                char c2 = s[left];
                freq[c2]--;
                left++;
            }
            
            mx = max(mx, right-left);
          
        }
        
        return mx;
    }
};
