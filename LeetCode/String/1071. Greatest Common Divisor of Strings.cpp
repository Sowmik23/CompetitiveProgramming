class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if(str2.size()>str1.size()) return gcdOfStrings(str2, str1);
        string res = str2;
        bool flag = false;

        while(flag==false){
            if(res=="") return res;
            while(res!="" and res!=str1.substr(0, res.size())) {
                res = res.substr(0, res.size()-1);
            }
            if(res=="") return res;
            if(str1.size()%res.size()!=0 or str2.size()%res.size()!=0 or !ifPossible(str1, str2, res)){
                res = res.substr(0, res.size()-1);
            }
            else flag = true;
        }
        return res;
    }
private:
    bool ifPossible(string &str1, string &str2, string &substr){
        int i = 0;
        while(i<str1.size()){
            string a = str1.substr(i, substr.size());
            if(a!=substr) return false;
            i +=substr.size();
        }
        i = 0;
        while(i<str2.size()){
            string a = str2.substr(i, substr.size());
            if(a!=substr) return false;
            i +=substr.size();
        }
        return true;
    }
};
