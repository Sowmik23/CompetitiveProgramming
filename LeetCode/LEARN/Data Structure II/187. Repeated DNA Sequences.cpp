class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> res;
        if(s.size()<=10) return res;
        
        unordered_map<string, int> mp;
        
        int i=0;
        int j=9;
        
        while(j<s.size()){
            // cout<<i<<" "<<j<<endl;
            //cout<<s.substr(i, j-i+1)<<endl;
            mp[s.substr(i, j-i+1)]++;
            j++;
            i++;
        }
        
        for(auto& m: mp){
           // cout<<m.first<<" "<<m.second<<endl;
            if(m.second>1){
                res.push_back(m.first);
            }
        }
        
        
        return res;
    }
};
