class WordDictionary {
public:
    
    //Time: O(n*word size)
    //Space: O(n)
    
    WordDictionary() {
        
    }
    
    void addWord(string word) {
    
        mp[word.size()].push_back(word);
    }
    
    bool search(string word) {
        
        for (auto &&s : mp[word.size()]){
            if (isEqual(s, word)) return true;
        }
        return false;
    }
private:
    unordered_map<int, vector<string>> mp;
    
    bool isEqual(string word1, string word2){
        for(int i=0;i<word1.size();i++){
            if(word2[i]=='.') continue;
            if(word1[i]!=word2[i]) return false;
        }
        
        return true;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
