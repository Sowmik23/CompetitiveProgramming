class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        //monotonic stack
        
        // Calculation procedure:
        // max value
        //   /\
        //  /--\
        // /----\
        
        int n = heights.size();
        int mx = 0;
        stack<int> stk;
        
        for(int i=0;i<=n;i++){
            while(!stk.empty() and (i==n or heights[stk.top()]>heights[i])){
                int prev = stk.top();
                stk.pop();
                if(stk.empty()){
                    mx = max(mx, heights[prev]*i);
                }
                else {
                    mx = max(mx, heights[prev]*(i-stk.top()-1));
                }
            }
           
            stk.push(i);
        }
//         while(!stk.empty()){

//             mx = max(mx, heights[stk.top()]* (n-(stk.empty() ? 0 : stk.top()+1)));
//             stk.pop();
//         }
        
        return mx;
    }
};
