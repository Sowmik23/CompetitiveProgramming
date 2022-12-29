struct TrieNode {
    int next[26], idx = -1;
    vector<int> indices;

    TrieNode() {
        fill(next, next+26, -1);
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {


        //Brute force: TLE: O(n^2*k)
        /*
        vector<vector<int>> res;

        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                string word1 = words[i]+words[j];
                string word2 = words[j]+words[i];
                if(isPalindrome(word1)) res.push_back({i, j});
                if(isPalindrome(word2)) res.push_back({j, i});
            }
        }
        return res;
        */


        //using trie
        /*
        trie.emplace_back();
        for (int i = 0; i < size(words); i++) add_string(words[i], i);
        for (int i = 0; i < size(words); i++) search(words[i], i);
        return ans;
        */

        //using hashMap
        vector<vector<int>> ans;
        unordered_map<string_view, int> m;
        for (int i = 0; i < size(words); i++) m[words[i]] = i;
        for (int i = 0; i < size(words); i++) {
            string rw = {rbegin(words[i]), rend(words[i])};
            string_view sv = words[i], rsv = rw;
            for (int len = 0; len <= size(sv); len++) {
                auto prefix = sv.substr(0, len), suffix = sv.substr(len);
                if (equal(begin(prefix), begin(prefix)+size(prefix)/2, rbegin(prefix))) {
                    auto it = m.find(rsv.substr(0, size(rsv)-len));
                    if (it != end(m) && it->second != i)
                        ans.push_back({it->second, i});
                }
                if (suffix.empty()) continue;
                if (equal(begin(suffix), begin(suffix)+size(suffix)/2, rbegin(suffix))) {
                    auto it = m.find(rsv.substr(size(rsv)-len));
                    if (it != end(m) && it->second != i)
                        ans.push_back({i, it->second});
                }
            }
        }
        return ans;
    }
private:
    bool isPalindrome(string word){
        for(int i=0;i<word.size()/2;i++){
            if(word[i]!=word[word.size()-1-i]) return false;
        }
        return true;
    }
    vector<TrieNode> trie;
    vector<vector<int>> ans;

    void add_string(string& s, int i) {
        int v = 0;
        for (int k = size(s)-1; k >= 0; k--) {
            if (isPal(s, 0, k)) trie[v].indices.push_back(i);
            char c = s[k] - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = size(trie);
                trie.emplace_back();
            }
            v = trie[v].next[c];
        }
        trie[v].idx = i;
        trie[v].indices.push_back(i);
    }

    void search(string& s, int i) {
        int v = 0, n = size(s);
        for (int k = 0; k < n; k++) {
            if (trie[v].idx != -1 && trie[v].idx != i && isPal(s, k, n-1))
                ans.push_back({i, trie[v].idx});
            char c = s[k] - 'a';
            if (trie[v].next[c] == -1) return;
            v = trie[v].next[c];
        }
        for (int j: trie[v].indices)
            if (i != j) ans.push_back({i, j});
    }

    bool isPal(string& s, int l, int r) {
        while (l < r) if (s[l++] != s[r--]) return false;
        return true;
    }
};
