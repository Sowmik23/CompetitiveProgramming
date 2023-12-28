// 2707. Extra Characters in a String
class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    bool is_word;
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        //recursive: TLE
        // return recursive(0, s, st, s.size());

        //recursion with memoization
        //Time: O(n^3)
        // unordered_map<int, int> mp;
        // return recursionWithMemo(0, s, st, mp, s.size());

        //using trie
        //Time: O(n^2 + m*k)
        int n = s.size();;
        auto root = buildTrie(dictionary);
        unordered_map<int, int> mp;

        return recursiveWithTrie(0, s, st, mp, root, n);
    }
private:    
    int recursive(int start, string &str, unordered_set<string> &st, int n){
        if(start==n) return 0;

        int cnt = recursive(start+1, str, st, n) + 1;
        for(int i=start;i<n;i++){
            string tmp = str.substr(start, i-start+1);
            if(st.count(tmp)){
                cnt = min(cnt, recursive(i+1, str, st, n));
            }
        }
        return cnt;
    }
    int recursionWithMemo(int start, string &str, unordered_set<string> &st, unordered_map<int, int>&mp, int n){
        if(start==n) return 0;
        if(mp.count(start)) return mp[start];

        int cnt = recursionWithMemo(start+1, str, st, mp, n) +1;
        for(int i=start;i<n;i++){
            string tmp = str.substr(start, i-start+1);
            if(st.count(tmp)){
                cnt = min(cnt, recursionWithMemo(i+1, str, st, mp, n));
            }
        }
        return mp[start] = cnt;
    }
    TrieNode* buildTrie(vector<string> &dictionary){
        auto root = new TrieNode();
        for(auto &word: dictionary){
            auto node = root;
            for(auto& ch: word){
                if(node->child.find(ch)==node->child.end()){
                    node->child[ch] = new TrieNode();
                }
                node = node->child[ch];
            }
            node->is_word = true;
        }
        return root;
    }
    int recursiveWithTrie(int start, string &str, unordered_set<string> &st, unordered_map<int, int> &mp, TrieNode* root, int n){
        if(start==n) return 0;
        if(mp.count(start)) return mp[start];
        int cnt = recursiveWithTrie(start+1, str, st, mp, root, n) + 1;
        TrieNode* node = root;
        for(int i=start;i<n;i++){
            char ch = str[i];
            if(node->child.find(ch)==node->child.end()) break;
            node = node->child[ch];
            if(node->is_word){
                cnt = min(cnt, recursiveWithTrie(i+1, str, st, mp, root, n));
            }
        }
        return mp[start] = cnt;
    }   
};