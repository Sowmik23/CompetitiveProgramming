class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     
        
        //Vertical approach is better than horizontal approach: 
        
        ///Horizontal Approach: 
        /*if(strs.empty()) return "";
        
        string prefix = strs[0];
        if(prefix=="") return "";
        
        for(int i=1;i<strs.size();i++){
            
            while(strs[i].find(prefix)!=0){
                prefix = prefix.substr(0, prefix.size()-1);
            }
            
            if(prefix=="") return "";
        }
        
        return prefix;
        */
        
        //Vertical Approach:
        
        if(strs.empty()) return "";
        for(int i=0;i<strs[0].size();i++){
            
            char ch = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j].size()==i or strs[j][i]!=ch){
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};
