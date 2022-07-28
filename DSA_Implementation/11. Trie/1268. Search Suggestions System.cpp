class TrieNode {
public:
    vector<int> similar;
    vector<TrieNode*> children;
    
    TrieNode() {
        children = vector<TrieNode*> (26, NULL);
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
        TrieNode* tmp = root;
        
        for(int i=0;i<word.size();i++){
            if(!tmp->children[word[i]-'a']){
                tmp->children[word[i]-'a'] = new TrieNode();
            }
            tmp = tmp->children[word[i]-'a'];
            tmp->similar.push_back(idx);
        }
    }
    
    vector<int> search(string word){
        
        TrieNode* tmp = root;
        for(int i=0;i<word.size();i++){
            tmp = tmp->children[word[i]-'a'];
            if(!tmp) return {};
        }
        return tmp->similar;
    }  
};

class Solution {
public:
    Trie* trie;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
     
        trie = new Trie();
        
        sort(products.begin(), products.end());
        for(int i=0;i<products.size();i++){
            trie->insert(products[i], i);
        }
      
        vector<vector<string>> res;
        vector<string> tmp;
        vector<int> t;
        string token="";
        for(int i=0;i<searchWord.size();i++){
            token+=searchWord[i];
            
            t = trie->search(token);
            for(int i=0;i<(t.size()>3 ? 3 : t.size());i++){
                //cout<<products[t[i]]<<" ";
                tmp.push_back(products[t[i]]);
            }
            //cout<<endl;
            res.push_back(tmp);
            tmp = vector<string> ();
        }
        
        return res;
    }
};
