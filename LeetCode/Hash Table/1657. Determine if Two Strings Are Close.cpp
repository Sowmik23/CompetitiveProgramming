class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if(word1.size()!=word2.size()) return false;

        vector<int> cnt1(26), cnt2(26);

        for(auto& w: word1) cnt1[w-'a']++;
        for(auto& w: word2) cnt2[w-'a']++;

        if(set(word1.begin(), word1.end())!=set(word2.begin(), word2.end())) return false;

        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        for(int i=0;i<26;i++) if(cnt1[i]!=cnt2[i]) return false;

        return true;
    }
};
