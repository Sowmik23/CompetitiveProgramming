class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        //Time: O(n)
        //Space: O(n)
        //Can you solve it without using extra space? see below:
       
        /*
        string res="";
        stack<char> stk;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=')' and s[i]!='('){
                res+=s[i];
            }
            if(s[i]=='('){
                stk.push('(');
                res+=s[i];
            }
            else if(s[i]==')'){
                if(!stk.empty() and stk.top()=='('){
                    //stk.push(')');
                    stk.pop();
                    res+=s[i];
                }
            }
        }
        
       // cout<<res<<endl;
        stk = stack<char> ();
        
        string ans="";
        for(int i=res.size()-1;i>=0;i--){
            if(res[i]!=')' and res[i]!='('){
                ans+=res[i];
            }
            if(res[i]==')'){
                stk.push(')');
                ans+=res[i];
            }
            else if(res[i]=='('){
                if(!stk.empty() and stk.top()==')'){
                    stk.pop();
                    ans+=res[i];
                }
            }
        }
        
        
        reverse(ans.begin(), ans.end());
        //cout<<ans<<endl;
        return ans;
        */
        
        
        //Time: O(n)
        //Space: O(1)
        
        //forward loop
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')'){
                if(cnt==0) s[i] = '#';
                else cnt--;
            }
        }
        
        //reverse loop
        cnt = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') cnt++;
            else if(s[i]=='('){
                if(cnt==0) s[i]='#';
                else cnt--;
            }
        }
        
        string res="";
        for(int i=0;i<s.size();i++){
            if(s[i]!='#') res+=s[i];
        }
        
        return res;
    }
};
