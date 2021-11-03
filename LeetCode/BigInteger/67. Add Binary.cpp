class Solution {
public:
    string addBinary(string a, string b) {
        
        string res="";
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        int x;
        
        while(i>=0 and j>=0){
            x = a[i]-'0' + b[j]-'0' +carry;
            if(x==2){
                x = 0;
                carry = 1;
            }
            else if(x==3){
                x = 1;
                carry = 1;
            }
            else {
                carry = 0;
            }
            
            res+=to_string(x);
            
            i--;
            j--;
        }
        while(i>=0){
            x = a[i]-'0' + carry;
            if(x==2){
                x = 0;
                carry = 1;
            }
            else carry = 0;
            res+=to_string(x);
            i--;
        }
        while(j>=0){
            x = b[j]-'0' + carry;
            if(x==2){
                x = 0;
                carry = 1;
            }
            else carry = 0;
            res+=to_string(x);
            j--;
        }
        
        if(carry==1){
            res+="1";
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
