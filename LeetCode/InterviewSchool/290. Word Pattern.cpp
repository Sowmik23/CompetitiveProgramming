class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char, int> mpPattern;
        unordered_map<string, int> mpWord;
       
        stringstream ss(s);
        string word;
        
        int i = 0;
        while(ss>>word){
            if(mpPattern[pattern[i]]!=mpWord[word]){
                return false;
            }
            else {
                mpPattern[pattern[i]] = mpWord[word] = i+1;
            }
            i++;
        }
        if(i<pattern.size()) return false;
        return true;
    }
};
