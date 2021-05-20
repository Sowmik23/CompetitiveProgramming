class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
     
        
        vector<vector<string>> res;
        unordered_map<string, vector<string> >ump;
        
        
        for(string str: paths){
            int i=0;
            while(str[i]!=' ') i++;
            
            string path = str.substr(0, i);
            // cout<<path<<endl;
            int k;
            int j = i+1;
            while(i<str.size()) {
                    
                if(str[i]=='('){
                    k = i+1;
                }
                else if(str[i]==')'){
                    string file_content = str.substr(k, i-k);
                    string file = path + '/' + str.substr(j, k-j-1);
                    // cout<<file_content<<" sowmik "<<file<<endl;
                    if(ump.find(file_content)==ump.end()){ //if file_content is new and not available in ump before
                        ump[file_content] = vector<string> ();
                    }
                    ump[file_content].push_back(file);
                    j = i+2;
                }
                i++;
            } 
        }
        
        for(auto i: ump){
            if(i.second.size()>1) res.push_back(i.second);
        }
        
        return res;
    }
};
