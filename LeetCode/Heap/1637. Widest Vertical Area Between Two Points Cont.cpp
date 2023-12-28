// 1637. Widest Vertical Area Between Two Points Containing No Points

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        priority_queue<int> pq;
        for(auto &point: points){
            pq.push(point[0]);
        }

        int diff = 0;
        int prev = -1;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(prev==-1){
                prev = x;
                continue;
            }
            diff = max(diff, prev-x);
            prev = x;
        }
        return diff;
    }
};