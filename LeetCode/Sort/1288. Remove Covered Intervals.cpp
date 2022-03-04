class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        
        //approach: sorting
        sort(intervals.begin(), intervals.end());
        
        for(auto& i: intervals){
            cout<<i[0]<<" "<<i[1]<<endl;
        }
        
        int res = intervals.size();
        int cnt = 0;
        
        int x = intervals[0][0];
        int y = intervals[0][1];
        int i = 1;
        
        while(i<intervals.size()){
            if(intervals[i][0]>=x and intervals[i][1]<=y){
                cnt++;
                i++;
            } 
            else if(intervals[i][0]<=x and intervals[i][1]>=y){
                cnt++;
                x = intervals[i][0];
                y = intervals[i][1];
                
                i++;
            }
            else {
                x = intervals[i][0];
                y = intervals[i][1];
                
                i++;
            }
        }
        
        
        return res-cnt;
    }
};
