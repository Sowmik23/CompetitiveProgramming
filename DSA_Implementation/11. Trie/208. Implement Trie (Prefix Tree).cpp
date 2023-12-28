class Trie {
    class TrieNode {
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
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* trieNode = this->root;
        for(auto& ch: word){
            if(!trieNode->children[ch-'a']){
               trieNode->children[ch-'a'] = new TrieNode();
            }
            trieNode = trieNode->children[ch-'a'];
        }
        trieNode->isWord = true;
    }

    bool search(string word) {
        TrieNode* trieNode = this->root;
        for(auto& ch: word){
            if(!trieNode->children[ch-'a']) return false;
            trieNode = trieNode->children[ch-'a'];
        }
        return trieNode->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* trieNode = this->root;
        for(auto& ch: prefix){
            if(!trieNode->children[ch-'a']) return false;
            trieNode = trieNode->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
///********************************************************

class Trie {
    unordered_map<char, Trie*> mp;
    bool isWord = false;

public:
    Trie() {

    }

    void insert(string word) {
        Trie* trieNode = this;
        for(auto& ch: word){
            if(!trieNode->mp.count(ch)){
                trieNode->mp[ch] = new Trie();
            }
            trieNode = trieNode->mp[ch];
        }
        trieNode->isWord = true;
    }

    bool search(string word) {
        Trie* trieNode = this;
        for(auto& ch: word){
            if(!trieNode->mp.count(ch))return false;
            trieNode = trieNode->mp[ch];
        }
        return trieNode->isWord;
    }

    bool startsWith(string prefix) {
        Trie* trieNode = this;
        for(auto& ch: prefix){
            if(!trieNode->mp.count(ch))return false;
            trieNode = trieNode->mp[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

///********************************************************

class Trie {
public:
    Trie() {

    }

    void insert(string word) {
        Trie* node = this;

        for(char ch: word){
            if(!node->mp.count(ch)){
                node->mp[ch] = new Trie();
            }
            node = node->mp[ch];
        }
        node->isWord = true;
    }

    bool search(string word) {

        Trie* node = this;
        for(char ch: word){
            if(!node->mp.count(ch)) return false;
            node = node->mp[ch];
        }

        return node->isWord;
    }

    bool startsWith(string prefix) {
        Trie* node = this;

        for(char ch: prefix){
            if(!node->mp.count(ch)) return false;
            node = node->mp[ch];
        }

        return true;
    }

private:
    unordered_map<char, Trie*> mp = {};
    bool isWord = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
