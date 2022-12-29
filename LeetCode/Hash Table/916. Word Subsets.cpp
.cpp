class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<string> res;
        unordered_map<int, int> mp;
        for(auto& word: words2){
            unordered_map<int, int> tmp;

            for(auto& ch: word){
                tmp[ch-'a']++;
            }
            for(int i=0;i<26;i++){
                mp[i] = max(mp[i], tmp[i]);
            }
        }

        for(auto& words: words1){
            unordered_map<int, int> tmp = mp;
            bool flag = true;

            for(auto& ch: words){
                tmp[ch-'a']--;
            }
            for(int i=0;i<26;i++){
                if(tmp[i]>0) {
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(words);
        }

        return res;
    }
};
