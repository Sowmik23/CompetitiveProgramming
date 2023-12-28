// 459. Repeated Substring Pattern
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        /*
        int start = 0;
        string str = "";
        str+=s[start];

        for(int i=1;i<s.size();i++){
            if(s[start]!=s[i]){
                str+=s[i];
                continue;
            }
            string word = s.substr(i);

            if(word.size()>=str.size()){
                if(str==word.substr(0, str.size())){
                    string tmp = word.substr(0, str.size());
                    bool flag = true;
                    while(word.size()>=str.size()){
                        tmp = word.substr(0, str.size());
                        if(str!=tmp) {
                            flag = false;
                            break;
                        }
                        word = word.substr(str.size());
                    }
                    cout<<word<<" : "<<endl;
                    if(flag and word.size()==0) return true;
                }
            }
        }
        return false;
        */


        //using divisors
        /*
        int n = s.size();
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                string patternConcat = "";
                for(int j=0;j<n/i;j++){
                    patternConcat+=s.substr(0, i);
                }
                if(patternConcat==s) return true;
            }
        }
        return false;
        */

        //string concatenation: Nice approach: Advanced
        string t = s+s;
        if(t.substr(1, t.size()-2).find(s)!=-1) return true;
        return false;


    }
};