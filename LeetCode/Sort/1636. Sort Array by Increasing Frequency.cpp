
class Solution {
    
    struct comp{
        bool operator()(pair<int, int> a, pair<int, int> b){
            if(a.second==b.second) return a.first<b.first;
            return a.second>b.second;
        }
    };
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        map<int, int> mp;
        vector<int> res;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        for(auto i: mp){
            pq.push(i);
        }
        
        int cnt;
        while(!pq.empty()){
            //cout<<pq.top().first<<" "<<pq.top().second<<endl;
            cnt = pq.top().second;
            while(cnt--) res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
    }
};
