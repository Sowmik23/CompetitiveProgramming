

//8888888*************************************

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

//8888888*************************************
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;
        for(auto& w: words){
            mp[w]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        for(auto& m: mp){
            // if(pq.size()>k) pq.pop();
            pq.push({m.second, m.first});
        }

        vector<pair<int, string>> tmp;
        while(!pq.empty()){
            tmp.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        sort(tmp.begin(), tmp.end(), [](auto& a, auto& b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        });
        vector<string> res;
        int cnt = 0;
        for(auto& t: tmp){
            cnt++;
            res.push_back(t.second);
            if(cnt==k) break;
        }
        return res;
    }
};
