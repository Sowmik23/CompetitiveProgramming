class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        vector<int> res;
        
        int i=num.size()-1;
        int carry = 0;
        int x;
        
        while(k and i>=0){
            x = k%10+num[i]+carry;
            if(x>9){
                x = x-10;
                carry = 1;
            }
            else carry = 0;
            
            res.push_back(x);
            
            i--;
            k/=10;
        }
        while(k){
            x = k%10 + carry;
            if(x>9){
                x = x-10;
                carry = 1;
            }
            else carry = 0;
            
            res.push_back(x);
            k/=10;
        }
        while(i>=0){
            x = num[i] + carry;
            if(x>9){
                x = x-10;
                carry = 1;
            }
            else carry = 0;
            
            res.push_back(x);
            i--;
        }
        if(carry==1) res.push_back(carry);
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
