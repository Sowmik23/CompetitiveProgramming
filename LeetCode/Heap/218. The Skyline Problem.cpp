class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        int n = buildings.size();
        vector<vector<int>> res;
        int i = 0,  currX, currHeight = 0;
        priority_queue<pair<int, int>> pq;

        while(i<n or !pq.empty()){
            currX = pq.empty() ? buildings[i][0] : pq.top().second;
            if(i>=n || buildings[i][0]>currX){
                while(!pq.empty() and pq.top().second<=currX)  pq.pop();
            }
            else {
                currX = buildings[i][0];
                while(i<n and buildings[i][0]==currX) {
                    pq.push({buildings[i][2], buildings[i][1]});
                    i++;
                }
            }
            currHeight = pq.empty() ? 0 : pq.top().first;
            if(res.empty() or (res.back()[1]!=currHeight)) res.push_back({currX, currHeight});
        }

        return res;
    }
};
