1234. Replace the Substring for Balanced String
class Solution {
public:
    int balancedString(string s) {
        
        int n = s.size();
        int k = n/4;
        unordered_map<char, int> mp;
        int res = n;

        for(auto& ch: s) mp[ch]++;

        int left = 0, right = 0;
        while(right<n){
            mp[s[right]]--;
            right++;
            while(left<n and mp['Q']<=k and mp['W']<=k and mp['E']<=k and mp['R']<=k){
                res = min(res, right-left);
                mp[s[left]]++;
                left++;
            }
        }
        return res;
    }
};