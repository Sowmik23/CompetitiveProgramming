class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        //Creative question, asked recently by Google
        //In Technical terms this problem is called Shortest Job First (SJF) scheduling algorithm in OS

        //TLE
        /*
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i=0;i<tasks.size();i++){
            pq.push({tasks[i][0], {tasks[i][1], i}});
            auto x = pq.top();
            pq.pop();

            while(!pq.empty() and pq.top().first<x.first+x.second.first){
                auto a = pq.top();
                pq.pop();
                pq.push({x.first+x.second.first, {a.second.first, a.second.second}});
            }
        }

        vector<int> res;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            res.push_back(x.second.second);
            while(!pq.empty() and pq.top().first<x.first+x.second.first){
                auto a = pq.top();
                pq.pop();
                pq.push({x.first+x.second.first, {a.second.first, a.second.second}});
            }
        }
        return res;
        */


        //SJF: Shortest Job first: OS
        //Time: nlogn
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = tasks.size();

        // One of the core concepts is how to persistent original index. This step is very smart!
        for(int i=0;i<n;i++) tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end());
        vector<int> res;

        long time = 0, i=0;
        while(i<n || !pq.empty()){
            if(pq.empty()){
                time = max(time, (long)tasks[i][0]);
            }
            while(i<n and time>=tasks[i][0]){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            auto [psTime, idx] = pq.top();
            pq.pop();
            res.push_back(idx);
            time+=psTime;
        }
        return res;
    }
};
