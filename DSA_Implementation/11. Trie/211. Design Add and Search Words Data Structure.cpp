// 211. Design Add and Search Words Data Structure


//TLE
class WordDictionary {
    class TrieNode{
    public:
        vector<TrieNode*> children;
        bool isWord;

        TrieNode(){
            children = vector<TrieNode*> (26, nullptr);            
            isWord = false;
        }

        ~TrieNode(){
            for(int i=0;i<26;i++){
                if(children[i]) delete children[i];
            }
        }
    };
public:
    TrieNode* root;
    WordDictionary() {
        this->root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* tmp = this->root;
        for(auto& ch: word){
            cout<<ch<<endl;
            if(!tmp->children[ch-'a']) {
                tmp->children[ch-'a'] = new TrieNode();
            }
            tmp = tmp->children[ch-'a'];
        }
        tmp->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = this->root;
        return customSearch(node, word, 0);
    }
private:
    bool customSearch(TrieNode* node, string word, int idx){

        TrieNode* tmp = node; //so if you not copy this pointer it will get TLE
        if(idx==word.size()) return node->isWord;

        char ch = word[idx];
        if(ch=='.'){
            for(int i=0;i<26;i++){
                if(tmp->children[i]){
                    bool res = customSearch(tmp->children[i], word, idx+1);
                    if(res) return true;
                }
                
            }
            return false;
        }
        else {
            if(!tmp->children[ch-'a']) return false;
            tmp = tmp->children[ch-'a'];
            return customSearch(tmp, word, idx+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */




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
