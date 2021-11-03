class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string res="";
        int l1 = num1.size();
        int l2 = num2.size();
        
        int i=l1-1;
        int j = l2-1;
        int carry = 0;
        while(i>=0 and j>=0){
            
            int x = num1[i] - '0';
            int y = num2[j] - '0';
            
            int s = x+y+carry;
            if(s>9){
                s = s-10;
                carry = 1;
            }
            else carry = 0;
            
            res+=to_string(s);
            i--;
            j--;
        }
       // cout<<res<<endl;
        
        while(i>=0){
            int s = (num1[i]-'0') +carry;
            if(s>9){
                s = s-10;
                carry = 1;
            }
            else carry = 0;
            res+=to_string(s);
            i--;
        }
        
        while(j>=0){
            int s = (num2[j]-'0') +carry;
            if(s>9){
                s = s-10;
                carry = 1;
            }
            else carry = 0;
            res+=to_string(s);
            j--;
        }
        
        if(carry==1){
            res+=to_string(carry);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
