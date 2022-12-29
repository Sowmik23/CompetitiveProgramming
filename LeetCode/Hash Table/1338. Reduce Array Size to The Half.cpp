class Solution {
public:
    int minSetSize(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int, int> mp;
        for(auto& i: arr){
            mp[i]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto& m: mp){
            pq.push({m.second, m.first});
        }

        int cnt = 0;
        int sum = 0;
        while(!pq.empty()){
            //cout<<pq.top().first<<" "<<pq.top().second<<endl;
            sum+=pq.top().first;
            cnt++;
            if(sum>=n/2) return cnt;
            pq.pop();
        }


        return cnt;
    }
};
