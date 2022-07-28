class TrieNode {
public:
    int sz;
    vector<TrieNode*> children;
    
    TrieNode(){
        children = vector<TrieNode*> (26, NULL);
        sz = 0;
    }
    
    ~TrieNode(){
        for(int i=0;i<26;i++){
            if(children[i]) delete children[i];
        }
    }
};

class Trie {
    TrieNode* root;
public:  
    Trie(){
        root = new TrieNode();
    }
    
    int insert(string word){
        TrieNode* tmp = root;
        for(int i=word.size()-1;i>=0;i--){
            if(!tmp->children[word[i]-'a']){
                tmp->children[word[i]-'a'] = new TrieNode();
            }
            tmp = tmp->children[word[i]-'a'];
        }
        tmp->sz = tmp->sz+word.size()+1;
        return tmp->sz;
    }
    
    bool search(string word){
        TrieNode* tmp = root;
        for(int i=word.size()-1;i>=0;i--){
            tmp = tmp->children[word[i]-'a'];
            if(!tmp) return false;
        }
        return true;
    }
};


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        //approach-01: using trie
        /*
        Trie* trie = new Trie();
        sort(words.begin(), words.end(), [](string &word1, string &word2){
            return word1.size()>word2.size();
        });
        
        int res = 0;
        for(int i=0;i<words.size();i++){
            if(!trie->search(words[i])){
                res+=trie->insert(words[i]);
            }
        }

        return res;
        */
        
        //approach-02: using set  
        //finding the suffix of the word in the set and removing
        //the word if the suffix exists in this set: Nice solution 
        //approximately O(n) time
        
        unordered_set<string> st;
        for(auto& word : words){
            st.insert(word);
        }
        
        for(auto& word : st){
            string str = word;
            while(str.size()>1){
                str = str.substr(1, str.size()-1);
                //cout<<str<<endl;
                if(st.count(str)>0) {
                    st.erase(str);
                    //break;
                }
            }
        }
        int res = 0;
        for(auto& word: st){
            res+=word.size();
        }
        res+=st.size();
        
        return res;
    }
};
