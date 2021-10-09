class Solution {
public:
    string reverseWords(string s) {
        
            
        
        ///Approach: using extra space : Stack
       /* stack<string> stk;
        
        string ans = "";
        
        stringstream ss(s);
        string word;
        
        while(ss>>word){
            cout<<word<<" ";
            stk.push(word);
        }
        
        if(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        
        while(!stk.empty()){
            ans+=" ";
            ans+=stk.top();
            stk.pop();
        }
        */
        
        
        //Approach: Not using any extra space: O(1)
        
        stringstream ss(s);
        string word;
        string ans = "";
        
        while(ss>>word){
            ans =word+" "+ans;
        }
        //cout<<ans<<endl;
        return ans.substr(0, ans.size()-1);
    }
};
