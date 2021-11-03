class Solution {
public:
    string longestPalindrome(string s) {
     
        //Time: O(n^2)
        
        string res;
        for(int i=0;i<s.size();i++){
            string tmp = expandFromMiddle(s, i, i);
            if(tmp.size()>res.size()) res = tmp;
            
            tmp = expandFromMiddle(s, i, i+1);
            if(tmp.size()>res.size()) res = tmp;
        }
        
        return res;
    }

private:
    string expandFromMiddle(string str, int i, int j){
        if(j>str.size()) return "";
        
        while(i>=0 and j<str.size() and str[i]==str[j]){
            i--;
            j++;
        }
        
        return str.substr(i+1, j-1-i); ///as last time i will be out of range and also j will be out of range of we need to increment i and decrement j
    }
};
