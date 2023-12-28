// 2325. Decode the Message
class Solution {
public:
    string decodeMessage(string key, string message) {
        
        unordered_map<char, char> mp;
        int i = 0;
        for(auto& ch: key){
            if(ch!=' ' and mp.find(ch)==mp.end()){
                mp[ch] = i+'a';
                i++;
            }
        }
        string res = "";
        for(auto& ch: message) {
            if(ch!=' ') res+=mp[ch];
            else res+=" ";
        }
        return res;
    }
};