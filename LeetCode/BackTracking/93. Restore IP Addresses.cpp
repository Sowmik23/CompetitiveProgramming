class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        //backtracking
        vector<string> res;
        if(s.size()<4 or s.size()>12) return res;

        backTrack(s, res, "", 0);
        return res;
    }
private:
    void backTrack(string str,  vector<string> &res, string ans, int cnt){

        if(cnt==4){
            if(str.size()==0) res.push_back(ans);
            return;
        }
        for(int i=1;i<=min(3, str.size());i++){
            string tmp = str.substr(0, i);
            if((tmp.size()>1 and tmp[0]=='0') or (tmp.size()==3 and stol(tmp)>255)) continue;
            backTrack(str.substr(i), res, ans+tmp+(cnt<3 ? "." : ""), cnt+1);
        }
    }
    int min(int a, int b){
        return a<b ? a : b;
    }
};
