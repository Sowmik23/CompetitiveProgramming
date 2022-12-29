class Solution {
public:
    bool checkIfPangram(string sentence) {

        unordered_map<int, bool> isCharPresent;

        for(auto& i: sentence) isCharPresent[i-'a'] = true;

        for(int i=0;i<26;i++){
            if(isCharPresent[i]==false)  return false;
        }
        return true;
    }
};
