// 168. Excel Sheet Column Title
class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string res = "";
        while(columnNumber){
            columnNumber--;
            int mod = columnNumber%26;
            res = (char)('A' + mod) + res;
            columnNumber = columnNumber/26;
        }
        return res;
    }
};