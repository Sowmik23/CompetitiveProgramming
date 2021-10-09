class Solution {
public:
    string reverseOnlyLetters(string s) {
     
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            
            if(((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')) and ((s[j]>='a' and s[j]<='z') or (s[j]>='A' and s[j]<='Z'))){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z'))) i++;
            else if(!((s[j]>='a' and s[j]<='z') or (s[j]>='A' and s[j]<='Z'))) j--;
        }
        
        return s;
    }
};
