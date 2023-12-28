class Solution {
public:
    string convert(string s, int numRows) {

        map<int, string> strVec;

        for(int i=0;i<s.size();){
            int cnt = 0;
            while(i<s.size() and cnt<numRows){
                strVec[cnt].push_back(s[i]);
                cnt++;
                i++;
            }
            for(int j=numRows-2;j>=1 and i<s.size();j--){
                strVec[j].push_back(s[i]);
                i++;
            }
        }
        string resStr = "";

        for(auto& [i, str]: strVec) resStr+=str;

        return resStr;
    }
};
