class Solution {
public:
    int scoreOfParentheses(string s) {
        
        //Time: O(n)
        //Space: O(n)
        
        stack<int> stk;
        stk.push(0);
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(0);
            }
            else {
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                
                stk.push(y+max(2*x, 1));
            }
        }
        
        return stk.top();
    }
};
