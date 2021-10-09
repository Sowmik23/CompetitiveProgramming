class Solution {
public:
    string reverseWords(string s) {
        
        string res = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' or i==s.size()-1){
                int j =i-1;
                if(i==s.size()-1) j = i;
                if(res.size()>0) res+=" ";
                while(j>-1 and s[j]!=' '){
                    res+=s[j];
                    j--;
                }
            }
        }
        
        return res;
    }
};
