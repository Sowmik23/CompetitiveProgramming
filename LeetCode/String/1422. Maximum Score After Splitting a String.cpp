// 1422. Maximum Score After Splitting a String

class Solution {
public:
    int maxScore(string s) {
        
        int cnt1 = 0;
        for(auto &ch: s){
            if(ch=='1') cnt1++;
        }
        if(cnt1==0) return s.size()-1;
        int cnt0 = 0;

        int mx = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0') cnt0++;
            else cnt1--;
            
            mx = max(mx, cnt0+cnt1);
        }
        
        return mx;
    }
};