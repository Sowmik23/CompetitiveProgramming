class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        
        sort(cost.begin(), cost.end());
        
        if(cost.size()==1) return cost[0];
        if(cost.size()==2) return cost[0]+cost[1];
        
        int res = 0;
        int cnt = 0;
        for(int i=cost.size()-1;i>=0;i--){
            if(cnt<2){
                res+=cost[i];
                cnt++;
            }
            else {
                cnt = 0;
            }
        }
        
        return res;
    }
};
