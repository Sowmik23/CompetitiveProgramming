class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        
        stringstream ss(s);
        string word ;
        
        unordered_map<char, int> patternMap;
        unordered_map<string, int> wordMap;
        
        int i = 0;
        while(ss>>word){
            if(i>=pattern.size()) return false;
           
            if(patternMap[pattern[i]]!=wordMap[word]) return false;
            else {
                patternMap[pattern[i]] = i+1;
                wordMap[word] = i+1;
            }
            i++;
        }
        if(i<pattern.size()) return false;
        
        return true;
    }
};
