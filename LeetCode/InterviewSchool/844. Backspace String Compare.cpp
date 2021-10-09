class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        
        ///Approach-01: Using Stack
        /*
        stack<char> stk1, stk2;
        
        for(char i: s){
            if(i=='#'){
                if(!stk1.empty()) stk1.pop();
                else continue;
            }
            else stk1.push(i);
        }
        for(char i: t){
            if(i=='#'){
               if(!stk2.empty()) stk2.pop();
                else continue;
            }
            else stk2.push(i);
        }
        
        if(stk1==stk2) return true;
        return false;
        */
        
        ///Approach-02: Two-Pointers : Time: O(n), Space: O(1)
        
        int i = s.size()-1;
        int j = t.size()-1;
        
        while(i>=0 or j>=0){
            int skipS = 0, skipT = 0;
            
            while(i>=0){
                if(s[i]=='#'){
                    skipS++;
                    i--;
                }
                else if(skipS>0){
                    skipS--;
                    i--;
                }
                else break;
            }
            
            while(j>=0){
                if(t[j]=='#'){
                    skipT++;
                    j--;
                }
                else if(skipT>0){
                    skipT--;
                    j--;
                }
                else break;
            }
            
            if(i>=0 and j>=0 and s[i]!=t[j]) return false;
            if((i>=0) != (j>=0)) return false;
            
            i--;
            j--;
        }
        
        return true;
    }
};
