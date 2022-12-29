class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        //Google interview question: Hard
        //priorty queue
        //Time: O(nlogn)
        //Space: O(N)

        long long totalFuel = startFuel;
        int cnt = 0;
        priority_queue<int> pq;
        int prev = 0;

        for(int i=0;i<stations.size();i++){
            int pos = stations[i][0];
            int fuel = stations[i][1];

            totalFuel-=pos-prev;
            while(!pq.empty() and totalFuel<0){
                totalFuel+=pq.top();
                pq.pop();
                cnt++;
            }

            if(totalFuel<0) return -1;
            pq.push(fuel);
            prev = pos;
        }

        totalFuel-=target-prev;
        while(!pq.empty() and totalFuel<0){
            totalFuel+=pq.top();
            pq.pop();
            cnt++;
        }
        if(totalFuel<0) return -1;

        return cnt;
    }
};
