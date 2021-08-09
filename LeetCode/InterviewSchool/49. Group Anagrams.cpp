class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     
        
        ///here, for sorting it uses nlogn time: so we can optimize in sorting part next time
        ///Time: O(nlogn)
        
      /*  unordered_map<string, vector<string>> mp;
        
        for(string& i: strs){
            string s1 = i;
            sort(s1.begin(), s1.end());
            mp[s1].push_back(i);
        }
        
        vector<vector<string>> res;
        
        for(auto& i: mp){
            res.push_back(i.second);
        }
        
        return res;
        */
        //Optimization: we can use counting sort instead of sort() function
        ///Time: O(n)
        
        unordered_map<string, vector<string>> mp;
        
        for(string& i: strs){
            string s1 = i;
            s1 = countingSort(s1);
            mp[s1].push_back(i);
        }
        
        vector<vector<string>> res;
        for(auto& i: mp){
            res.push_back(i.second);
        }
        return res;
    }
    
private:
    string countingSort(string str){ ///counting sort : O(n)
        int count[26] = {0};
        for(char ch: str){
            count[ch-'a']++;
        }
        
        string s;
        int j = 0;
        while(j<26){
            if(count[j]==0){
                j++;
            }
            else {
                s.push_back(j+'a');
                count[j]--;
            }
        }
        
        return s;
    }
};
