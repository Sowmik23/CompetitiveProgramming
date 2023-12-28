class Solution {
public:
    string countAndSay(int n) {

        string str = "1";
        if(n==1) return str;

        for(int i=2;i<=n;i++){
            str = generateString(str);
        }
        return str;
    }
private:
    string generateString(string str){
        string res = "";
        int cnt = 1;
        int i = 1;
        for(i=1;i<str.size();i++){
            if(str[i]==str[i-1]) cnt++;
            else {
                res+=to_string(cnt);
                res+=str[i-1];
                cnt = 1;
            }
        }
        res+=to_string(cnt);
        res+=str[i-1];

        return res;
    }
};
