class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        
        //prim's minimum spanning tree
        int n = points.size();
        
        //min priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n, false);
        
        int i = 0;
        int connected = 1; 
        int res = 0;
        
        while(connected<n){
            visited[i] = true;
            for(int j=0;j<n;j++){
                if(visited[j]==false){
                    int distance = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                
                    pq.push({distance, j});
                }
            }   
            
            while(visited[pq.top().second]==true){
                pq.pop();
            }
            
            res+=pq.top().first;
            i = pq.top().second;
            pq.pop();
            connected++;
        }
        
        return res;
    }
};
