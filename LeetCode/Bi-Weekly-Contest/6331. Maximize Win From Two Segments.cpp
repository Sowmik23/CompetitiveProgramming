// 6331. Maximize Win From Two Segments

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        
        int n = prizePositions.size();
        long long kWindow = (k+1)*2;
        
        if(kWindow>=n) return n;
        
        unordered_map<int, int> mp;
        for(auto& prize: prizePositions) mp[prize]++;
        
        
        vector<long> bigWindowMx = slidingWindowMax(prizePositions, mp, kWindow);
        int giantMax = bigWindowMx[0];
        // cout<<"Giant: "<<giantMax<<endl;
        
        vector<long> mx = slidingWindowMax(prizePositions, mp, k+1);
        long mx1 = mx[0];
        long start1 = mx[1];
        // cout<<"@nd: "<<mx1<<" "<<start1<<endl;
        
        for(int i=start1-k;i<=start1;i++) mp[i] = 0;
        
        vector<long> mx2 = slidingWindowMax(prizePositions, mp, k+1);
        long mx22 = mx2[0];
        long start2 = mx2[1];
        // cout<<"@rd: "<<mx22<<" "<<start2<<endl;
        
        return max(giantMax, (mx1+mx22));
    }
private:
    int max(int x, int y){ return x>y ? x : y; }
    
    vector<long> slidingWindowMax(vector<int>& prizePositions, unordered_map<int, int> &mp, long window){
        long mx = 0;
        int i = 1;
        long start = 0;
        long cnt = 0;
        
        while(i<=prizePositions.size() and i<=window){
            cnt+=mp[i];
            i++;
        }
        // mx = max(mx, cnt);
        if(mx<cnt){
            mx = cnt;
            start = i-1;
        }
        
        while(i<=prizePositions.size()){
            cnt+=mp[i];
            cnt-=mp[i-window];
            if(mx<cnt){
                mx = cnt;
                start = i;
            }
            i++;
        }
        return {mx, start};
    }
};