// 942. DI String Match


class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        int low = 0 ;
        int high = s.size();
        vector<int> res;

        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                res.push_back(low);
                low++;
            }
            else {
                res.push_back(high);
                high--;
            }
        }
        res.push_back(low);
        return res;
    }
};