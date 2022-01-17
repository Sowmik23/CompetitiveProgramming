class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        long res = 0;
        for(int i=0;i<columnTitle.size();i++){
            res = res*26 + columnTitle[i]-'A' + 1;
        }
        
        return res;
    }
};
