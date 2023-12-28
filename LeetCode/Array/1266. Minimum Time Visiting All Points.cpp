// 1266. Minimum Time Visiting All Points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int res = 0;
        int x = points[0][0];
        int y = points[0][1];
        for(int i=1;i<points.size();i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int distance = getDistance(x, y, x1, y1);
            x = x1;
            y = y1;
            res+=distance;
        }
        return res;
    }
private:
    int getDistance(int x1, int y1, int x2, int y2){
        return max(abs(x1-x2), abs(y1-y2));
    }
};