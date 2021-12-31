class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int res = 0;
        
        for(int i=0;i<n;i++){
            unordered_map<string, int> mp;
            int duplicate = 1;
            
            for(int j=i+1;j<n;j++){
                if(points[i][0]==points[j][0] and points[i][1]==points[j][1]){
                    duplicate++;        
                }
                else {
                    int dx = points[j][0]-points[i][0];
                    int dy = points[j][1]-points[i][1];
                    
                    int g = gcd(dx, dy);
                    mp[to_string(dx/g)+"_"+to_string(dy/g)]++;
                }
            }
            
            res = max(res, duplicate);
            for(auto& i: mp){
                res = max(res, i.second+duplicate);
            }
        }
        
        return res;
    }
private:
    int gcd(int a, int b){
        
        if(b==0) return a;
        return gcd(b, a%b);
    }
};
