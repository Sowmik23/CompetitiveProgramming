// 447. Number of Boomerangs
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int n = points.size();
        int res = 0;
        
        for(int i=0;i<n;i++){
            unordered_map<long, int> mp;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                else {
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];

                    int dx = (x1-x2);
                    int dy = (y1-y2);
                    // double distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
                    long distance = dx*dx + dy*dy;
                    mp[distance]++;
                }
            }
            for(auto& m: mp){
                if(m.second>1){
                    res+=(m.second*(m.second-1));
                }
            }
        }
        
        return res;
    }
};