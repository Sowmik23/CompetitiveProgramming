class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        ///Time Complexity: NlogN: We can do it O(N) by using counting sort for sorting the str
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        
        for(int i=0;i<strs.size();i++){
            
            string str = strs[i];
            sort(str.begin(), str.end());
            
            mp[str].push_back(strs[i]);
        }
        
        for(auto& i: mp){
            res.push_back(i.second);
        }
        
        
        return res;
    }
};
