class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
//         sort(pairs.begin(), pairs.end());
        
//         vector<vector<int>> res;
        
//         for(auto i: pairs){
//             if(res.empty() or res.back()[1]<i[0]){
//                 res.push_back(i);
//             }
//             else {
//                 res.back()[1] = max(res.back()[1], i[1]);
//             }
//         }
        
//         return res.size();
        
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b){ 
            return a[1]<b[1];
        });
        
        int curr = INT_MIN, res = 0;
        for(auto i: pairs){
            if(curr<i[0]){
                curr = i[1];
                res++;
            }
        }
        
        return res;
    }
};
