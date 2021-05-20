
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        //approach-01: time: O(n), memory: O(n)
      /*  map<int, char> mp;
        
        int j=0;
        for(int i: indices){
            mp[i] = s[j];
            j++;
        }
        
       // map is automaitcally sorted by index
        j = 0;
        for(auto i: mp){
            s[j] = i.second;
            j++;
        }
        
        return s;
        */
        ///apporach:-02
        string str=s; ///if you don't initialize with previous string, it will give wrong ans
        for(int i=0;i<indices.size();i++){
            str[indices[i]] = s[i];
        }
        return str;
    }
};
