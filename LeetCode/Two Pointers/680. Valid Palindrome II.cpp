// 680. Valid Palindrome II
class Solution {
public:
    bool validPalindrome(string s) {
        
        int n = s.size();
        int i = 0, j = n-1;

        bool flag = false;
        while(i<j){
            if(s[i]!=s[j]) return isPalindrome(s, i+1, j) or isPalindrome(s, i, j-1);
            i++;
            j--;
        }
        return true;
    }
private:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};