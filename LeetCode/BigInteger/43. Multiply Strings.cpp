class Solution {
public:
    string multiply(string num1, string num2) {
        
        
        //Time: O(num1.size()*num2.size())
        ///O(m*n)
        
        if(num1=="0" or num2=="0") return "0";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int n = num1.size()+num2.size();
        string res(n, '0');  //initialize result string with chars '0'
        
        //now multiply each digit of num2 with num1;
        for(int i=0;i<num2.size();i++){
            int digit2 = num2[i]-'0';
            
            for(int j=0;j<num1.size();j++){
                int digit1 = num1[j]-'0';
                
                
                int numZeros = i+j;
                int carry = res[numZeros] - '0';
                
                int multiply = digit1*digit2 + carry;
                
                res[numZeros] = (multiply%10)+'0';
                res[numZeros+1] += (multiply/10);
            }
        }
        
        //removing leading zeros if any...
        if(res.back()=='0') res.pop_back();
        reverse(res.begin(), res.end());
        
        return res;
    }
};
