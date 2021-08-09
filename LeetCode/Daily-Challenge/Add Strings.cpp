class Solution {
public:
    string addStrings(string num1, string num2) {
        
        if(num1.size()<num2.size()) return addStrings(num2, num1);
        
        string res;
        
        int x;
        int carry = 0;
        int j = num2.size()-1;
        for(int i=num1.size()-1;i>=0;i--){
            if(j>=0){
                x = num1[i] - '0' + num2[j] - '0' + carry;
                carry = x/10;
                res.push_back((x%10) + '0');
                j--;
            }
            else {
                x = num1[i] - '0' + carry;
                carry = x/10;
                res.push_back((x%10) + '0');
            }
        }
        if(carry>0) res.push_back(carry+'0');
        
        
        for(int i=0;i<res.size()/2;i++){
            swap(res[i], res[res.size()-i-1]);
        }
        
        
        return res;
    }
};
