// 1854. Maximum Population Year
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        
        //Line Sweep Algorithm
        vector<int> dates(2051, 0);
        for(auto& log: logs){
            dates[log[0]]++;
            dates[log[1]]--;
        }

        //calculate prefix sum
        for(int i=1951;i<=2050;i++){
            dates[i]+=dates[i-1];
        }

        int res = 0;
        //caculate max value
        for(int i=1950;i<=2050;i++){
            if(dates[i]>dates[res]) res = i;
        }
        return res;
    }
};