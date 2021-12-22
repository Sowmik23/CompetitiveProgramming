class Solution {
public:
    int maxPower(string s) {
        
        int left = 0, right = 1;
        int mx = 1;
        
        while(right<s.size()){
            int cnt = 1;
            while(s[right]==s[right-1]){
                right++;
                cnt++;
            } 
            mx = max(mx, cnt);
            right++;
            left++;
        }
        
        return mx;
    }
};
