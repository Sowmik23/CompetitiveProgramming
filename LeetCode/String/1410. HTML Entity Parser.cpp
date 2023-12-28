// 1410. HTML Entity Parser
class Solution {
public:
    string entityParser(string text) {
        
        int n = text.size();
        unordered_map<string, string> mp;
        mp["&quot;"] = '"';
        mp["&apos;"] = "'";
        mp["&amp;"] = "&";
        mp["&gt;"] = ">";
        mp["&lt;"] = "<";
        mp["&frasl;"] = "/";

        int prev = -1;
        bool flag = false;
        string res = "";
        int i = 0;

        while(i<n){
            if(text[i]=='&'){
                if(flag==true){
                    string str = text.substr(prev, i-prev);
                    res+=str;
                }
                prev = i;
                flag = true;
            }
            else if(text[i]==';' and flag==true){
                string str = text.substr(prev, i-prev+1);
                // cout<<str<<endl;
                if(mp.find(str)!=mp.end()){
                    res+=mp[str];
                }
                else res+=str;
                flag = false;
                i++;
                continue;
            }
            if(flag!=true){
                res+=text[i];
            }
            i++;
        }
        if(flag==true){
            string str = text.substr(prev, i-prev);
            // cout<<str<<endl;
            res+=str;
        }
        
        return res;
    }
};