class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char, int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]] = i+1;  //map the order of the chars
        }

        for(int i=0;i<words.size()-1;i++){
            for(int j=0;j<words[i].size();j++){
                if(j>=words[i+1].size()) return false;
                if(words[i][j]!=words[i+1][j]){
                    int a = mp[words[i][j]];
                    int b = mp[words[i+1][j]];
                    if(a>b) return false; //only check the first char's of the words
                    break;
                }
            }
        }
        return true;
    }
};
