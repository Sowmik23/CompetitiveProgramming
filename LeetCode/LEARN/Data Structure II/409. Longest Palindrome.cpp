class Solution {
public:
    int longestPalindrome(string s) {
        
        int cnt[52] =  {0};
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' and s[i]<='Z'){
                cnt[s[i]-'A'+26]++;
            }
            else {
                cnt[s[i]-'a']++;
            }
        }
        
        bool flag = true;
        int res = 0;
        for(int i=0;i<52;i++){
            if(cnt[i]%2==1){
                flag = false;
                cnt[i]--;
            }
            res+=cnt[i];
        }
        
        if(flag==false) res+=1;
        return res;
    }
};
