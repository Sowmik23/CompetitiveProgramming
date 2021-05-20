class Solution {
public:
    bool isNumber(string s) {
        
        bool number = false, exponent = false, dot = false;
        
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' and s[i]<='9'){
                number  = true;
            }
            else if(s[i]=='e' or s[i]=='E'){
                if(number==false or exponent==true) return false;
                exponent = true;
                number = false;
            }
            else if(s[i]=='.'){
                if(exponent==true or dot==true) return false;
                dot = true;
            }
            else if(s[i]=='+' or s[i]=='-'){
                if(i!=0 and s[i-1]!='e' and s[i-1]!='E') return false;
            }
            else return false;
        }
        
        return number;
    }
};
