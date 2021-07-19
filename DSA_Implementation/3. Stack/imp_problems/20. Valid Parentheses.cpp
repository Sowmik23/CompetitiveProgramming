class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                stk.push(s[i]);
            }
            else {
                if(stk.empty()==true) return false;
                char top = stk.top();
                if(s[i]==')' and top!='(') return false;
                else if(s[i]=='}' and top!='{') return false;
                else if(s[i]==']' and top!='[') return false;
                else {
                    stk.pop();
                }
            }
        }
        
        if(!stk.empty()) return false;
        
        return true;
    }
};
