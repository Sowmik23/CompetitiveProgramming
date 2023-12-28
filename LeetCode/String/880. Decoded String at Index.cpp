// 880. Decoded String at Index

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        
        long long total_length = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='1' and s[i]<='9') total_length *= (int)(s[i]-'0');
            else total_length++;
        }

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>='1' and s[i]<='9'){
                total_length/=(s[i]-'0');
                k = k % total_length;
            }
            else {
                if(total_length==k or k==0) return string(1, s[i]);
                total_length--;
            }
        }
        return "";
    }
};