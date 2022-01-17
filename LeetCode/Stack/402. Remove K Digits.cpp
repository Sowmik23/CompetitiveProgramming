class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k==num.size()) return "0";
        
        stack<char> stk;
       
        for(int i=0;i<num.size();i++){
            
            while(!stk.empty() and stk.top()>num[i] and k>0){
                stk.pop();
                k = k-1;
            }
            stk.push(num[i]);
        }
        
        while(k>0){
            stk.pop();
            k--;
        }
        
        string res = "";
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        
        reverse(res.begin(), res.end());
        
        int i = 0;
        while(res[i]=='0' and i<res.size()-1) i++;
        
        return res.substr(i, res.size());
    }
};
