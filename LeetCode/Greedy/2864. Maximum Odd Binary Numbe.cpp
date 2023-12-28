// 2864. Maximum Odd Binary Numbe

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        //very interesting problem
        // To make a number odd, the last bit must be 1


        // First count the total number of 1
        // After that, concate 1 from first except one 1 for last bit. That's it
        int totalOne = 0;
        for(int i=0;i<s.size();i++){
            totalOne += s[i]=='1' ? 1 : 0;
        }

        string res = "";
        for(int i=0;i<s.size();i++){
            if(totalOne>1) {
                res+="1";
                totalOne--;
            }
            else res+="0";
        }
        //remote last 0 and insert reserved 1
        res.pop_back();
        res+="1";

        return res;
    }
};
// 1
// 11
// 101
// 111
// 1001
// 1011