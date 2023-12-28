//FollowUp Questions Solution:
//Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 10^9, and you want to check one by one to
//see if t has its subsequence. In this scenario, how would you change your code?

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> hash; //chars -> list of indices;
        for(int i=0; i<t.length();i++) hash[t[i]].push_back(i);

//s = "abc", t = "ahbgdc"

        int prev = -1;
        for(auto c : s){
            auto it = hash.find(c);
            if(it == hash.end()) return false;
            auto vec = it->second;
            int pos = upper_bound(vec.begin(), vec.end(), prev) - vec.begin(); // find the first pos whose value is greater than prev
            if(pos == vec.size()) return false;
            prev = vec[pos];
        }
        return true;
    }
};


//General Solution:

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int i=0;
        int j = 0;
        if(s.size()>t.size()) return false;
        for(i=0;i<t.size();i++){
            if(j>=s.size()) return true;
            if(s[j]==t[i]) j++;
        }
        if(j==s.size()) return true;
        return false;
    }
};


class Solution {
public:
    bool isSubsequence(string s, string t) {

        if(s.size()>t.size()) return false;


        //recursion
        //int ln = dp(0, 0, s, t);


        //recursion with memoization
        vector<vector<int>> memo(s.size()+2, vector<int> (t.size()+2, -1));
        int ln = dpWithMemoization(0, 0, s, t, memo);

        if(ln == s.size()) return true;
        return false;
    }
private:
    //recursion
    int dp(int i, int j, string s, string t){
        if(i>=s.size() or j>=t.size()) return 0;

        if(s[i]==t[j]){
            return 1+dp(i+1, j+1, s, t);
        }
        else return dp(i, j+1, s, t);
    }

    //recursion with memoization
    int dpWithMemoization(int i, int j, string s, string t, vector<vector<int>> &memo){
        if(i>=s.size() or j>=t.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];

        if(s[i]==t[j]){
            return memo[i][j] = 1+dpWithMemoization(i+1, j+1, s, t, memo);
        }
        return memo[i][j] = dpWithMemoization(i, j+1, s, t, memo);
    }
};
