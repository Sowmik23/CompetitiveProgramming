class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        vector<string> res;
        unordered_set<string> st(words.begin(), words.end());

        for(auto& word: words){
            vector<bool> visited(word.size());
            if(dfs(word, visited, st, 0)) res.push_back(word);
        }
        return res;
    }
private:
    bool dfs(string word, vector<bool> &visited, unordered_set<string> &st, int i){
        if(i==word.size()) return true;
        if(i>word.size()) return false;
        if(visited[i]) return false;

        visited[i] = true;

        for(int j=word.size()-(i==0 ? 1 : 0);j>i;j--){
            string tmp = word.substr(i, j-i);
            if(st.count(tmp) and dfs(word, visited, st, j)) return true;
        }
        return false;
    }
};
