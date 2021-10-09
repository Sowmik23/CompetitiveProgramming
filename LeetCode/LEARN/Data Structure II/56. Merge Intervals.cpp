class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
        if(intervals.size()==0) return intervals;
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> tmp = intervals[0];
        
        for(int i=1;i<intervals.size();i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            
            if(a<=tmp[1]){
                tmp[1] = max(b, tmp[1]);
            }
            else {
                res.push_back(tmp);
                tmp = intervals[i];
            }
        }
        res.push_back(tmp);
        
        return res;
    }
};
