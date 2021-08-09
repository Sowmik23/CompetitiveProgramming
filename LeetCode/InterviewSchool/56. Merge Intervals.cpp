class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        ///Approach: Sorting: Time: nlogn
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        for( auto i: intervals){
            
            if(res.empty() or i[0]>res.back()[1]){
                res.push_back(i);
            }
            else {
                res.back()[1] = max(res.back()[1], i[1]);
            }
        }
        
        
        return res;
    }
};
