#############################409. Longest Palindrome
public:
    int longestPalindrome(string s) {
        
        vector<int> upper(26, 0);
        vector<int> lower(26, 0);
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' and s[i]<='Z') upper[s[i]-'A']++;
            else lower[s[i]-'a']++;
        }
        
        bool hasOdd = false;
        int res = 0;
        for(int i=0;i<upper.size();i++){
            if(upper[i]%2==0){
                res+=upper[i];
            }
            else {
                upper[i]--;
                hasOdd = true;
                res+=upper[i];
            }
        }
        for(int i=0;i<lower.size();i++){
            if(lower[i]%2==0){
                res+=lower[i];
            }
            else {
                lower[i]--;
                hasOdd = true;
                res+=lower[i];
            }
        }
        
        
        if(hasOdd) return res+1;
        return res;
    }




##############################5. Longest Palindromic Substring
public:
    string longestPalindrome(string s) {
        
        //Time: O(n^2)
        //Space: O(n)
        
        string res="";
        for(int i=0;i<s.size();i++){
            string tmp = lenOfPalindrome(i, i, s);
            if(tmp.size()>res.size()) res = tmp;
            
            tmp = lenOfPalindrome(i, i+1, s);
            if(tmp.size()>res.size()) res = tmp;
        }
        
        return res;
    }
private:
    string lenOfPalindrome(int i, int j, string str){
        if(i<0 or j>=str.size()) return "";
        
        while(i>=0 and j<str.size() and str[i]==str[j]){
            i--;
            j++;
        }
        // cout<<i<<" "<<j<<str.substr(i+1, j-i-1)<<endl;
        
        return str.substr(i+1, j-i-1);
    }



###################################647. Palindromic Substrings(Total Number of palindromic substring
class Solution {
public:
    int countSubstrings(string s) {
        
        //Time: O(n^2)
        //Space: O(1)
        
        int ans = 0;
        for(int i=0;i<s.size();i++){
            
            int left = i;
            int right = i;
            
            //this check is for ex: a
            while(left>=0 and right<s.size() and s[left]==s[right]){
                ans++;
                left--;
                right++;
            }
            
            
            //this check is for ex: ab or aa
            left = i;
            right =  i+1;
            while(left>=0 and right<s.size() and s[left]==s[right]){
                ans++;
                left--;
                right++;
            }
        }
        
        return ans;
    }
};



