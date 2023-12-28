// 2580. Count Ways to Group Overlapping Ranges
class Solution {
public:
    const int mod = 1e9+7;
    int countWays(vector<vector<int>>& ranges) {
        
        int n = ranges.size();
        sort(ranges.begin(), ranges.end());
        
        int x = ranges[0][0];
        int y =ranges[0][1];

        int cnt = 0;
        
        for(int i=1;i<n;i++){
            auto& r = ranges[i];
            
            if(r[0]<=y){
                y = max(y, r[1]);
            }
            else {
                cnt++;
                x= ranges[i][0];
                y = ranges[i][1];
            }
        }
        cnt++;
        long p = 2, q = cnt;

        return pow(p, q)%mod;
    }
private:
    int pow(int p, int q){
        long res = 1;
        while (q != 0) {
            if (q % 2 == 1) {   
                res = (res*(long long)p)%mod;
                res%=mod;
                q--;
            }
            else {
                q /= 2;   
                p = ((long long)p*p)%mod;  
                p%=mod;
            }
        }
        return (int)res%mod;
    }
};