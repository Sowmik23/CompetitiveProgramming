class Solution {
public:
    string decodeString(string s) {
        
        stack<char> stk;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]!=']'){
                stk.push(s[i]);
            }
            else {
                string str="";
                while(stk.top()!='['){
                    str = stk.top() + str;
                    stk.pop();
                }
                
                stk.pop(); //remove '['
                
                string num ="";
                while(!stk.empty() and isDigit(stk.top())){
                    num = stk.top()+num;
                    stk.pop();
                }
               // cout<<num<<endl;
                int k = stoi(num);
                
                for(int i=0;i<k;i++){
                    for(int j=0;j<str.size();j++){
                        stk.push(str[j]);
                    }
                }
            }
        }
        
        string ans="";
        while(!stk.empty()){
            ans = stk.top()+ans;
            stk.pop();
        }
        
        return ans;
    }
private:
    bool isDigit(char ch){
        if(ch>='0' and ch<='9') return true;
        return false;
    }
};
