class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> stk;
        int a, b, res;
        
        for(string i: tokens){
            if(isOperator(i)){
                a = stk.top();
                stk.pop();
                b = stk.top();
                stk.pop();
                
                if(i=="+") res = a+b;
                else if(i=="-") res = b-a;
                else if(i=="*") res = b*a;
                else if(i=="/") res = b/a;
                
                stk.push(res);
            }
            else {
                stk.push(stoi(i));
            }
        }
        return stk.top();
    }
private:
    bool isOperator(string ch){
        if(ch=="+" or ch=="-" or ch=="*" or ch=="/") return true;
        return false;
    }
};
