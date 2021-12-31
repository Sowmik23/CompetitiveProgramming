class Solution {
public:
    int calculate(string s) {
     
        //Time: O(n)
        //Space: O(n)
        
        stack<int> stk;
        
        int currentNumber = 0;
        char operation = '+';
        for(int i=0;i<s.size();i++){
            char currentChar = s[i];
            
            if(isDigit(currentChar)){
                currentNumber = currentNumber*10 + (currentChar-'0');
            }
            if(!isDigit(currentChar) and currentChar!=' ' || i==s.size()-1){
                if(operation=='-'){
                    currentNumber*=-1;
                    stk.push(currentNumber);
                }
                else if(operation=='+'){
                    stk.push(currentNumber);
                }
                else if(operation=='*'){
                    int x = stk.top();
                    stk.pop();
                    stk.push(x*currentNumber);
                }
                else if(operation=='/'){
                    int x = stk.top();
                    stk.pop();
                    stk.push(x/currentNumber);
                }
                
                operation = currentChar;
                currentNumber = 0;
            }
        }
        
        int res = 0;
        while(!stk.empty()){
           // cout<<stk.top()<<endl;
            res+=stk.top();
            stk.pop();
        }
        
        return res;
    }
private:
    bool isDigit(char ch){
        int x = ch-'0';
        if(x>=0 and x<=9) return true;
        return false;
    }
};
