class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        
        //Using Monotonic stack
        // Time: O(n)
        // Space: O(n)
        
//         vector<int> res(temperatures.size(), 0);
//         stack<pair<int, int>> stk;
        
//         for(int i=0;i<temperatures.size();i++){
//             while(!stk.empty() and temperatures[i]>stk.top().first){
//                 res[stk.top().second] = i-stk.top().second; 
//                 stk.pop();
//             }
            
//             stk.push({temperatures[i], i});
//         }
        
//         return res;
        
        
        //optimized version
        
        stack<int> stk;
        vector<int> res(temperatures.size(), 0);
        
        for(int i=0;i<temperatures.size();i++){
            while(!stk.empty() and temperatures[i]>temperatures[stk.top()]){
                res[stk.top()] = i-stk.top();
                stk.pop();
            }
            
            stk.push(i);
        }
        
        return res;
    }
};
