class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_map<int, bool> mp;
        for(auto& b: banned) mp[b] = true;
        
        long sum = 0;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(mp[i]!=true){
                sum+=i;
                if(sum<=maxSum) cnt++;
                else break;
            }
        }
        return cnt;
    }
};