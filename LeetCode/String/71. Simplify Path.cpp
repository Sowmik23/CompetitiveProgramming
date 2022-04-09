class Solution {
public:
    string simplifyPath(string path) {
        
        string res = "";
        
        vector<string> str;
        stringstream ss(path);
        
        string dir = "";
        while(getline(ss, dir, '/')){
            if(dir=="" or dir==".") continue;
            if(dir==".." and !str.empty()) str.pop_back();
            else if(dir!="..") str.push_back(dir);
        }
        
        for(auto& s: str) res+="/"+s;
        if(res.size()==0) res+="/";
        
        return res;
    }
};
