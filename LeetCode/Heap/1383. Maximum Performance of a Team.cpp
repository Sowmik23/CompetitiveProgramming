class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

        vector<pair<int, int>> performance;
        for(int i=0;i<n;i++){
            performance.push_back({efficiency[i], speed[i]});
        }

        sort(rbegin(performance), rend(performance)); //sort descending order of efficiency

        priority_queue<int, vector<int>, greater<int>> pq;  //min priority queue

        long sum = 0;
        long res = 0;
        for(auto& p: performance){
            sum+=p.second;
            pq.push(p.second);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            res = max(res, sum*p.first);
        }

        return res%(int)(1e9+7);
    }
};
