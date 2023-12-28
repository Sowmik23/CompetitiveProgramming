class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;
        int n = intervals.size();

        //just consider these three cases
        for(auto& i: intervals){
            if(newInterval[0]>i[1]){
                res.push_back(i);
            }
            else if(newInterval[1]<i[0]){
                res.push_back(newInterval);
                newInterval = i;
            }
            else {
                newInterval[0] = min(i[0], newInterval[0]);
                newInterval[1] = max(i[1], newInterval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
