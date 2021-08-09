class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        unordered_map<char, int> dictionary;
        string first_row = "qwertyuiop";
        string second_row = "asdfghjkl";
        string third_row = "zxcvbnm";
        
        for(int i=0;i<first_row.size();i++){
            dictionary[first_row[i]] = 1;
        }
        for(int i=0;i<second_row.size();i++){
            dictionary[second_row[i]] = 2;
        }
        for(int i=0;i<third_row.size();i++){
            dictionary[third_row[i]] = 3;
        }
        
        vector<string> res;
        for(int i=0;i<words.size();i++){
            string str = words[i];
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            int sample = dictionary[str[0]];
            bool flag = true;
            for(int j = 1;j<str.size();j++){
                if(dictionary[str[j]]!=sample){
                    flag = false;
                }
            }
            
            if(flag==true) res.push_back(words[i]);
        }
        
        return res;
    }
};
