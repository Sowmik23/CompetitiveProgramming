class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), [](auto& a, auto& b){
            return a[1]<b[1];
        });

        int cnt = 1;
        int x = points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=x){
                continue;
            }
            else {
                cnt++;
                x = points[i][1];
            }
        }
        return cnt;
    }
};
