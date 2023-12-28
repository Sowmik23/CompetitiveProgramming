class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {

        int n = plantTime.size();
        vector<pair<int, int>> mergedTime;

        for(int i=0;i<n;i++){
            mergedTime.push_back({growTime[i], plantTime[i]});
        }
        sort(mergedTime.begin(), mergedTime.end(), greater<pair<int, int>>());


        int total = 0;
        int res = 0;
        for(int i=0;i<n;i++){
            total+=mergedTime[i].second;
            int forOne  = total+mergedTime[i].first;
            res = max(res, forOne);
        }

        return res;
    }
};


// 2 3 5 1 6
// 20 5 4 3 2
