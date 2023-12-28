class Solution {
public:
    int n;
    int len;
    int subStringSize;
    unordered_map<string, int> mp;

    ///Time: O(s.size()*words.size()*word.size())


    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;

        n = words.size();
        len = words[0].size();
        subStringSize = n*len;

//         for(auto& word: words) mp[word]++;

//         for(int i=0;i<s.size()-len+1;i++){
//             if(checkIfPossible(i, s)){
//                 res.push_back(i);
//             }
//         }

//         return res;


        unordered_map<string, int> mp;
        for(auto &word : words) mp[word]++;

        for(int i = 0; i + n * len <= s.size(); i++){
            unordered_map<string, int> seen;
            for(int j = 0; j < n; j++){
                string str = s.substr(i + j * len, len);
                seen[str]++;
                if(seen[str] > mp[str]) break;
                if(j == n - 1) res.push_back(i);
            }
        }
        return res;
    }
private:
    bool checkIfPossible(int idx, string s){
        unordered_map<string, int> usedWord = mp;
        int used = 0;

        for(int i=idx;i<idx+subStringSize;i+=len){
            string str = s.substr(i, len);

            if(usedWord[str]>0){
                usedWord[str]--;
                used++;
            }
            else break;
        }

        return used==n;
    }
};
