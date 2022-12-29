class Solution {
public:
    string oddString(vector<string>& words) {

        map<vector<int>, string> mp1;
        map<vector<int>, int> mp2;

        for(int i=0;i<words.size();i++){
            string str = words[i];
            vector<int> tmp;
            for(int j=0;j<str.size()-1;j++){
                tmp.push_back(str[j+1]-'a' - str[j]-'a');
            }

            mp1[tmp] = str;
            mp2[tmp]++;
        }
        for(auto& m: mp2){
            if(m.second==1){
               // cout<<mp1[m.first];
                return mp1[m.first];
            }
        }

        return "";
    }
};
