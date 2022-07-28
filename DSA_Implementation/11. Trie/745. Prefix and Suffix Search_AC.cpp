class TrieNode {
    public:
        vector<TrieNode*> children;
        int index ;
        TrieNode(){
            children = vector<TrieNode*> (27, NULL);
            index = -1;
        }
        
        ~TrieNode(){
            for(int i=0;i<26;i++){
                if(children[i]) delete children[i];
            }
        }
};

class Trie {
    public:
        TrieNode* root;
        
        Trie(){
            root = new TrieNode();
        }
    
        void insert(string s, int idx){
            TrieNode* cur = root;
            for(int i=0;i<s.size();i++)
            {
                if(cur->children[s[i]-'a'] == NULL){
                    cur->children[s[i]-'a'] = new TrieNode();
                }
                cur = cur->children[s[i]-'a'];
                cur->index = idx;
            }
        }
    
        int search(string word){
            TrieNode* curr = root;
            for(int i=0;i<word.size();i++){
                curr = curr->children[word[i]-'a'];
                if(!curr) return -1;
            }
            
            return curr->index;
        }
};

class WordFilter {
public:   
    Trie *trie = new Trie();
    WordFilter(vector<string>& words) 
    {    
        int idx = 0;
        string s = "";
        
        for(auto &word : words) 
        {
            s = "{" + word;
            trie->insert(s, idx);
            
            for(int i=word.size()-1; i>=0; i--) 
            {
                s = word[i] + s;
                trie->insert(s, idx);
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        
        string match = suffix + "{" + prefix;
        int ansIdx = trie->search(match);
        return ansIdx;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
