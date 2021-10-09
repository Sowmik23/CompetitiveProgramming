class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        if(palindrome.size()==1) return "";
        
        if(palindrome[0]!='a') {
            palindrome[0] = 'a';
            return palindrome;
        }
        int i = 0;
        while(i<palindrome.size()){
            if(palindrome[i]=='a') i++;
            else {
                if(i==(palindrome.size()/2)){
                    i++;
                    continue;
                } 
                else break;
            }
        }
        if(i<palindrome.size()) {
            palindrome[i] = 'a';
        }
        else {
            palindrome[palindrome.size()-1] = 'b';
        }
        
        return palindrome;
    }
};
