#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string longestPalindrome(string str) {
        
        //approach-01: Brute Force: O(n^3)
        
        
        //approach-02: Expand Around Center: Time: O(n^2), Space: O(1)
        /*
        if(str=="" or str.size()<1) return "";
        
        string res;
        
        for(int i=0;i<str.size();i++){
            string tmp = expandFromMiddle(str, i, i);
            
            if(tmp.size()>res.size()) res = tmp;
            
            tmp = expandFromMiddle(str, i, i+1);
            
            if(tmp.size()>res.size()) res = tmp;
        } 
        
        return res;
        */
        
        //Approach-03: DP: Time: O(n^2), Space: O(1)
        
        int len = str.size();
        if(len==0) return "";
        
        vector<vector<bool>> dp(len, vector<bool> (len, false));
        
        for(int i=0;i<len;i++){
            dp[i][i] = true;
            if(i==len-1) break;
            dp[i][i+1] = (str[i]==str[i+1]);
        }
        
        //dp
        for(int i=len-3;i>=0;i--){
            for(int j=i+2;j<len;j++){
                dp[i][j] = (dp[i+1][j-1] and (str[i]==str[j]));
            }
        }
        
        //get maxstr result
        int mx = 0;
        string maxstr = "";
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(dp[i][j]==true and j-i+1>mx){
                    mx = j-i+1;
                    maxstr = str.substr(i, j-i+1);
                }
            }
        }
        
        return maxstr;
            
        //Approach-04: Manacher's Algorithm, Time: O(n), Space: O(1)
    }
    
private:
    string expandFromMiddle(string s, int left, int right){
        if(right>s.size()) return "";

        while(left>=0 and right<s.size() and s[left]==s[right]){
            left--;
            right++;
        }

        return s.substr(left+1, right-left-1);
    }
};

int main(){
	
	Solution s;
	
	string str = "forgeeksskeegfor";
	
	cout<<s.longestPalindrome(str)<<endl;
	
	return 0;
}
