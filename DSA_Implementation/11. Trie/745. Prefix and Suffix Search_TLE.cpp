class TrieNode {
    public:
        vector<int> wordsIndex;
        vector<TrieNode*> children;
        
        TrieNode(){
            children = vector<TrieNode*> (26, nullptr);
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
    
        void insert(string word, int idx){
            root->wordsIndex.push_back(idx);
            TrieNode* curr = root;
            
            for(int i=0;i<word.size();i++){
                if(!curr->children[word[i]-'a']){
                    curr->children[word[i]-'a'] = new TrieNode();
                }
                curr = curr->children[word[i]-'a'];
                curr->wordsIndex.push_back(idx);
            }
        }
    
        vector<int> search(string word){
            TrieNode* curr = root;
            for(int i=0;i<word.size();i++){
                curr = curr->children[word[i]-'a'];
                if(!curr) return {};
            }
            
            return curr->wordsIndex;
        }
        ~Trie(){}
};

class WordFilter {
public:
    Trie *prefixTrie, *suffixTrie;
    
    WordFilter(vector<string>& words) {
        prefixTrie = new Trie();
        suffixTrie = new Trie();
        
        for(int i=0;i<words.size();i++){
            string word = words[i];
            
            prefixTrie->insert(word, i);
            reverse(word.begin(), word.end());
            suffixTrie->insert(word, i);
        }
        
    }
    
    int f(string prefix, string suffix) {
        vector<int> plist = prefixTrie->search(prefix);
        reverse(suffix.begin(), suffix.end());
        vector<int> slist = suffixTrie->search(suffix);
        
        //now find intersection of plist and slist and return max index
        int i = plist.size()-1;
        int j = slist.size()-1;
        
        while(i>=0 and j>=0){
            cout<<plist[i]<<" "<<slist[j]<<endl;
            if(plist[i]==slist[j]) return plist[i];
            if(plist[i]>slist[j]) i--;
            else j--;
        }
        
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
