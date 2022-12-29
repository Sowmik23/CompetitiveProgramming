class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;
        for(auto& w: words){
            mp[w]++;
        }

        auto comparator = [](auto& a, auto& b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comparator)> pq(comparator);

        for(auto& m: mp){
            pq.push({m.second, m.first});
            if(pq.size()>k) pq.pop();
        }

        vector<string> res;
        while(!pq.empty()){
            //cout<<pq.top().second<<" "<<pq.top().first<<endl;
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;
        for(auto& w: words){
            mp[w]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        for(auto& m: mp){
            // if(pq.size()>k) pq.pop();
            pq.push({m.second, m.first});
        }

        vector<pair<int, string>> tmp;
        while(!pq.empty()){
            tmp.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        sort(tmp.begin(), tmp.end(), [](auto& a, auto& b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        });
        vector<string> res;
        int cnt = 0;
        for(auto& t: tmp){
            cnt++;
            res.push_back(t.second);
            if(cnt==k) break;
        }
        return res;
    }
};
