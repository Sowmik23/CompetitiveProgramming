

//Approach-01: Two pointer
class Solution {
public:
    string longestPalindrome(string s) {

        string res = "";
        for(int i=0;i<s.size();i++){

            string str = checkPalindrome(s, i, i);
            if(str.size()>res.size()) res = str;
            str = checkPalindrome(s, i, i+1);
            if(str.size()>res.size()) res = str;
        }
        return res;
    }
private:
    string checkPalindrome(string str,  int i, int j){
        cout<<i<<" f "<<j<<endl;
        if(i<=j){
            while((i>=0 and j<str.size()) and str[i]==str[j]){
                i--;
                j++;
            }
        }
        return str.substr(i+1, j-i-1);
    }
};


//Approach-02: DP
