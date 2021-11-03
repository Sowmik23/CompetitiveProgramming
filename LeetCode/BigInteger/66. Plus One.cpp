class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> res;
        int carry = 0;
        
        int x = digits[digits.size()-1]+1;
        if(x>9){
            x = x-10;
            carry = 1;
        }
        res.push_back(x);
        
        for(int i=digits.size()-2;i>=0;i--){
            x = carry+digits[i];
            if(x>9){
                x = x-10;
                carry = 1;
            }
            else carry = 0;
            
            res.push_back(x);
        }
        
        if(carry==1) res.push_back(carry);
        reverse(res.begin(), res.end());
        
        return res;
    }
};
