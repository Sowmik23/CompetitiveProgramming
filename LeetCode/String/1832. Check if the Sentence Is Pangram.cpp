class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        map<char, int> mp;
        
        for(auto i: sentence){
            mp[i]++;
        }
        for(char i='a'; i<='z';i++){
            if(mp[i]<1) return false; 
        }
        return true;
    }
};
