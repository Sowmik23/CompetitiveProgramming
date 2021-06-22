class Solution {
public:
    string toLowerCase(string s) {
       
        ///solution using STL
        //transform(s.begin(), s.end() , s.begin(), ::tolower);
        
        ///approach-02:
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' and s[i]<='Z'){
                s[i] = (s[i] - 'A') + 'a';
            }
        }
        
        return s;
    }
};
