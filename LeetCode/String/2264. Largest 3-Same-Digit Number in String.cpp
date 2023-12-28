// 2264. Largest 3-Same-Digit Number in String

class Solution {
public:
    string largestGoodInteger(string num) {
        
        string res = "";
        for(int i=0;i<num.size()-2;i++){
            if(isSame(num, i)){
                string tmp = "";
                tmp+=num[i];
                tmp+=num[i];
                tmp+=num[i];
                if(res=="") res = tmp;
                else if(res.size()>0 and res<tmp) res = tmp;
            }
        }
        return res;
    }
private:
    bool isSame(string num, int i){
        return (num[i]==num[i+1] and num[i+1]==num[i+2]);
    }
};