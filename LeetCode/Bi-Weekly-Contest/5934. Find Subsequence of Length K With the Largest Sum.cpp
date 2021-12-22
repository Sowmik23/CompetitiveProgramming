class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i], i});
        }
        
        vector<pair<int, int>> v;
        int cnt = 0;
        vector<int> res;
        while(!pq.empty()){
            v.push_back({pq.top().second, pq.top().first});
            //res.push_back(pq.top());
            pq.pop();
            cnt++;
            
            if(cnt==k) break;
        }
        
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            // cout<<v[i].first<<" "<<v[i].second<<endl;
            res.push_back(v[i].second);
        }
        
        return res;
    }
};
