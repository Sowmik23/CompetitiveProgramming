class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        
        //Time: O(n)
        //Space:O(n)
        
        int m = pushed.size();
        int n = popped.size();
        if(m!=n) return false;
        
        stack<int> stk;
        
        int i = 0;
        int j = 0;
        while(i<m){
            if(pushed[i]==popped[j]){
                j++;
                while(!stk.empty() and j<n and stk.top()==popped[j]){
                    stk.pop();
                    j++;
                }
                i++;
            }
            else {
                stk.push(pushed[i]);
                i++;
            }
        }
        
        if(j<n or !stk.empty()) return false;
        return true;
    }
};
