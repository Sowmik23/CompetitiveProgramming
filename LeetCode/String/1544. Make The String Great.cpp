class Solution {
public:
    string makeGood(string s) {

        stack<char> stk;
        int i = 0;

        while(i<s.size()){
            while(!stk.empty() and ((stk.top()==s[i]-'A'+'a') or (stk.top()-'A'+'a'==s[i])) and i<s.size()){
                stk.pop();
                i++;
            }
            stk.push(s[i]);
            i++;
        }

        string res = "";
        while(!stk.empty()){
            if((stk.top()>='a' and stk.top()<='z') or (stk.top()>='A' and stk.top()<='Z')) res = stk.top()+res;
            stk.pop();
        }
        return res;
    }
};
