class Solution {
public:
    bool isPalindrome(string s) {
        
        string str = "";
        for(int i=0;i<s.size();i++){
            if((s[i]>='A' and s[i]<='Z') or (s[i]>='a' and s[i]<='z') or (s[i]>='0' and s[i]<='9')){
                str+=tolower(s[i]);
            }
        }
       // cout<<str<<endl;
        for(int i=0;i<str.size()/2;i++){
            if(str[i]!=str[str.size()-i-1]) return false;
        }
        
        return true;
    }
};
