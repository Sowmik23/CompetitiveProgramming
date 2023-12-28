// 1578. Minimum Time to Make Rope Colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int res = 0;

        int i = 1;
        while(i<colors.size()){
            int sum = neededTime[i-1];
            int mx = neededTime[i-1];
            if(colors[i]==colors[i-1]){
                while(i<colors.size() and colors[i]==colors[i-1]){
                    sum+=neededTime[i];
                    mx = max(mx, neededTime[i]);
                    i++;
                }
                res+=(sum-mx);
            } else i++;
        }
        return res;
    }
};