class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        
        int m  = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> efforts(m, vector<int> (n, INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        int directions[5] = {1, 0, -1, 0, 1};
        
        pq.push({0, 0}); //first one is effort, second is position
        while(!pq.empty()){
            int top_effort = pq.top().first;
            int x = pq.top().second/100;
            int y = pq.top().second%100;
            pq.pop();
            
            if(top_effort>=efforts[x][y]) continue;
            efforts[x][y] = top_effort;
            
            for(int i=0;i<4;i++){
                int x1 = x + directions[i];
                int y1 = y + directions[i+1];
                
                if(x1>=0 and x1<m and y1>=0 and y1<n) {
                    int effort = max(top_effort, abs(heights[x1][y1]-heights[x][y]));
                    pq.push({effort, x1*100 + y1});
                }
            }
        }
        
        return efforts[m-1][n-1];
    }
};
};
