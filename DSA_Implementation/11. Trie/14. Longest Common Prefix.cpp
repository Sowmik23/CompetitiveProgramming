class Solution {
    class TrieNode {
    public:
        vector<TrieNode*> children;
        int len;
        bool isWord ;

        TrieNode(){
            children = vector<TrieNode*> (26, NULL);
            len = 0;
            isWord = false;
        }
        ~TrieNode(){
            for(int i=0;i<26;i++){
                if(children[i]) delete children[i];
            }
        }
    };
    class Trie {
        public:
        unordered_map<char, Trie*> mp;
        bool isWord;
    };
public:
    string longestCommonPrefix(vector<string>& strs) {

        //horizontal approach
        /*
        string res = strs[0];
        for(int i=1;i<strs.size();i++){
            string word = strs[i];
            while(word!=res){
                if(word.size()>res.size()){
                    word = word.substr(0, word.size()-1);
                }
                else res = res.substr(0, res.size()-1);
            }
        }
        return res;
        */

        //verticall approach

        //using trie
        //first of all insert into the tie
        /*
        TrieNode* root1 = new TrieNode();
        for(auto& word: strs){
            TrieNode* root = root1;
            for(auto& ch: word){
                if(!root->children[ch-'a']){
                    root->children[ch-'a'] = new TrieNode();
                }
                root->children[ch-'a']->len++;
                root = root->children[ch-'a'];
            }
            root->isWord = true;
        }

        TrieNode* trieNode = root1;
        int n = strs.size();
        string word = strs[0];
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            if(trieNode->children[ch-'a']!=NULL and trieNode->children[ch-'a']->len==n) {
                trieNode = trieNode->children[ch-'a'];
            }
            else return word.substr(0, i);
        }

        return word;
        */


        //using trie : but another way

        Trie* root1 = new Trie();
        for(auto& word: strs){
            Trie* root = root1;
            for(auto& ch: word){
                if(root->mp.find(ch)==root->mp.end()){
                    root->mp[ch] = new Trie();
                }
                root = root->mp[ch];
            }
            root->isWord = true;
        }

        string res = "";
        while(root1 and !root1->isWord and root1->mp.size()==1){
            auto it = root1->mp.begin();
            res+=it->first;
            root1 = it->second;
        }
        return res;
    }
};
