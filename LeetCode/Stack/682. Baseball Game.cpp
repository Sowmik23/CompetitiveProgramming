class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> stk;
        
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="C"){
                stk.pop();
            }
            else if(ops[i]=="D"){
                int x = stk.top();
                x *=2;
                stk.push(x);
            }
            else if(ops[i]=="+"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.push(x);
                stk.push(x+y);
            }
            else {
                int x = stoi(ops[i]);
                stk.push(x);
            }
        }
        
        int res = 0;
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        
        return res;
    }
};
