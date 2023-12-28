

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
class Solution {
public:
    string longestPalindrome(string s) {

        //Notice: not subsequence, it's substring
        //Dynamic Programming/two pointer
        //Time: O(n^2)

        //approach-01: Brute Force: O(n^3)


        //approach-02: Expand Around Center: Time: O(n^2), Space: O(1)

        //two pointer
        // string res = "";
        // for(int i=0;i<s.size();i++){
        //     string tmp = checkPalindrom(s, i, i);
        //     if(res.size()<tmp.size()) res = tmp;
        //     tmp = checkPalindrom(s, i, i+1);
        //     if(res.size()<tmp.size()) res = tmp;
        // }
        // return res;


        //Approach-03: DP: Time: O(n^2), Space: O(1)
        //DP approach:
        //tabulation
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        //all 1 length's are palindrome
        for(int i=0;i<n;i++) dp[i][i] = 1;

        int mxLen = 1, start = 0;

        //if adjacent 2 char's are same then they are palindrome
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) {
                dp[i][i+1] = 1;

                mxLen = 2;
                start = i;
            }
        }

        //here k is the length of the substring
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                //starting index i and length k
                int j = i+k-1;

                if(dp[i+1][j-1]==1 and s[i]==s[j]) {
                    dp[i][j] = 1;

                    //store the result
                    if(k>mxLen) {
                        mxLen = k;
                        start = i;
                    }
                }
            }
        }
        // cout<<start<<" "<<mxLen<<endl;
        return s.substr(start, mxLen);

        //Approach-04: Manacher's Algorithm, Time: O(n), Space: O(1)
        //Manacher's algorithm

        string str="";
        for(int i=0;i<s.size();i++){
            str+="$";
            str+=s[i];
        }
        str+="$";

        // cout<<"Input string: "<<str<<endl;

        vector<int> palindrom(str.size(), 0);
        int start = 0, end = 0;

        for(int i=0;i<str.size();){
            while(start>0 and end<str.size()-1 and str[start-1]==str[end+1]){
                start--;
                end++;
            }

            palindrom[i] = end-start+1;
            if(end==str.size()-1) break;

            int newCenter = end + (i%2==0 ? 1 : 0);
            for(int j=i+1;j<=end;j++){
                palindrom[j] = min(palindrom[i-(j-i)], 2*(end-j)+1);
                if(j+palindrom[i-(j-i)]/2 == end){
                    newCenter = j;
                    break;
                }
            }
            i = newCenter;
            end = i+palindrom[i]/2;
            start = i-palindrom[i]/2;

        }

        int mx = INT_MIN;
        int idx = 0;
        for(int i=0;i<palindrom.size();i++){
            if(mx<palindrom[i]){
                mx = palindrom[i];
                idx = i;
            }
        }
       // cout<<mx<<" "<<idx<<endl;

        string res = "";
        for(int st=idx-mx/2;st<=idx+mx/2;st++){
            if(str[st]!='$') res+=str[st];
        }

        return res;

    }
private:
    string checkPalindrom(string str, int i, int j){
        if(i>j) return "";
        while((i>=0 and j<str.size()) and str[i]==str[j]){
            i--;
            j++;
        }
        return str.substr(i+1, j-i-1);
    }
};
