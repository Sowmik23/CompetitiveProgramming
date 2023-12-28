class Solution {
public:
    int numDecodings(string s) {

        if(s[0]=='0')  return 0;

        //recursion: TLE
        // return recursive(s, s.size());

        // recursion with memoization
        vector<int> memo(s.size()+1, -1);
        return recursionWithMemo(s, memo, s.size());
    }
private:
    int recursive(string s, int i){
        if(i==0 or i==1)  return 1;
        if(s[0]=='0') return 0;

        int cnt = 0;
        if(s[i-1]>'0') cnt = recursive(s, i-1);
        if(s[i-2]=='1' or s[i-2]=='2'  and s[i-1]<'7') cnt+=recursive(s, i-2);
        return cnt;
    }

    int recursionWithMemo(string s, vector<int> &memo, int i){
        if(i==0 or i==1)  return 1;
        // if(s[0]=='0') return 0;
        if(memo[i-1]!=-1) return memo[i-1];

        int cnt = 0;
        if(s[i-1]>'0') cnt = recursionWithMemo(s, memo, i-1);
        if(s[i-2]=='1' or s[i-2]=='2' and s[i-1]<'7') cnt+=recursionWithMemo(s, memo, i-2);
        memo[i-1] = cnt;
        return memo[i-1];
    }
};


class Solution {
public:
    int numDecodings(string s) {

        if(s.size()==0) return 0;
        vector<int> memo(s.size()+1, -1);

        return dp(s, memo, 0);
    }
private:
    int dp(string &s, vector<int> &memo, int i){

        if(i>s.size()) return 0;
        if(s[i]=='0') return 0;

        if(i==s.size()) return 1;
        if(memo[i]!=-1) return memo[i];

        int res = dp(s, memo, i+1);
        memo[i] = res;

        if(i+1<s.size() and (s[i]=='1' or (s[i]=='2' and s[i+1]<'7'))) res+=dp(s, memo, i+2);
        memo[i] = res;
        return res;
    }
};




class Solution {
public:
    int numDecodings(string s) {
        
        if(s[0]=='0') return 0;

        //recursive: MLE
        //return numOfWays(0, s);

        //with memoization
        vector<int> memo(s.size()+1, -1);
        return recursionWithMemo(0, memo, s);
    }
private:
    int numOfWays(int i, string s){
        if(i>s.size()) return 0;
        if(i==s.size()) return 1;

        int cnt = 0;
        if(s[i]!='0') cnt = numOfWays(i+1, s);
        if(i+1<s.size() and (s[i]=='1' or (s[i]=='2' and s[i+1]<'7'))){
            cnt += numOfWays(i+2, s);
        } 
        return cnt;
    }

    int recursionWithMemo(int i, vector<int> &memo, string s){
        if(i>s.size()) return 0;
        if(i==s.size()) return 1;

        if(memo[i]!=-1) return memo[i];
        
        int cnt = 0;
        if(s[i]!='0') cnt = recursionWithMemo(i+1, memo, s);
        if(i+1<s.size() and (s[i]=='1' or (s[i]=='2' and s[i+1]<'7'))){
            cnt +=recursionWithMemo(i+2, memo, s);
        }
        return memo[i] = cnt;
    }
};
