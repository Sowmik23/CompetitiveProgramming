class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string> res;

        for(auto& w : words){
            string word = w;

            unordered_map<char, int> wrd, ptrn;
            int i = 0; //as the length of word and pattern is always same so one i is enough
            bool flag = true;

            while(i<word.size()){
                if(wrd[word[i]] !=ptrn[pattern[i]]){
                    flag = false;
                    break;
                }
                else {
                    wrd[word[i]] = ptrn[pattern[i]] = i+1;
                }
                i++;
            }
            if(i!=pattern.size()) flag = false;

            if(flag) res.push_back(word);
        }

        return res;
    }
};
