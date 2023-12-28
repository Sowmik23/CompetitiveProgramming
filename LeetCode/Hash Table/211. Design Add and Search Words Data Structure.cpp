// 211. Design Add and Search Words Data Structure
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
    //using Trie it get's TLE
    // TrieNode* root;

    
    //Another way is hashmap
    unordered_map<int, vector<string>> mp;

    WordDictionary() {
        //this->root = new TrieNode();

        mp = unordered_map<int, vector<string>>();
    }
    
    void addWord(string word) {
        /*
        TrieNode* tmp = this->root;
        for(auto& ch: word){
            cout<<ch<<endl;
            if(!tmp->children[ch-'a']) {
                tmp->children[ch-'a'] = new TrieNode();
            }
            tmp = tmp->children[ch-'a'];
        }
        tmp->isWord = true;
        */

        int sz = word.size();
        mp[sz].push_back(word);
    }
    
    bool search(string word) {

        /*
        TrieNode* node = this->root;
        return customSearch(node, word, 0);
        */

        int x = word.size();
        auto& tmp = mp[x];
        for(auto& str: tmp){
            bool flag = true;
            for(int i=0;i<str.size();i++){
                if(word[i]=='.') continue;
                if(word[i]!=str[i]){
                    flag = false;
                    break;
                } 
            }
            if(flag) return true;
        }
        return false;
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