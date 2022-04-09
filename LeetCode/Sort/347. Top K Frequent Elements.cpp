class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //approach-01: TIME: nlogn
        /*
        unordered_map<int, int> mp;
        for(auto& num: nums){
            mp[num]++;
        }
        
        priority_queue<pair<int, int>> pq;
        
        for(auto& h: mp){
            pq.push({h.second, h.first});
        }
        
        vector<int> res;
        while(!pq.empty() and k>0){
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
        */
        
        //approach-02: hashMap + Counting sort
        //Time: O(n)
        //Space: O(n)
        /*
        unordered_map<int, int> mp;
        for(auto& num: nums){
            mp[num]++;
        }
        
        vector<pair<int, int>> numsWithFreq;
        for(auto& h: mp){
            numsWithFreq.push_back({h.second, h.first});
        }
        
        int MIN = INT_MAX;
        int MAX = INT_MIN;
        for(auto& num: nums){
            MIN = min(MIN, num);
            MAX = max(MAX, num);
        }
        //cout<<MAX<<" "<<MIN<<endl;
        
        int range = MAX-MIN+5;
        vector<int> cnt(range, 0);
        vector<pair<int, int>> sortedNums(numsWithFreq.size());
        
        for(auto& n: numsWithFreq){
            cnt[n.first]++;
        }
        
        for(int i=1;i<cnt.size();i++){
            cnt[i] +=cnt[i-1];
        }
        
        for(int i=numsWithFreq.size()-1;i>=0;i--){
            sortedNums[cnt[numsWithFreq[i].first]-1] =  numsWithFreq[i];
            cnt[numsWithFreq[i].first]--;
        }
        
        vector<int> res;
        for(int i=sortedNums.size()-1;i>=0;i--){
            k--;
            res.push_back(sortedNums[i].second);
            if(k==0) break;
        }
            
        return res;
        */
        
        //approach-03: hashmap + bucket sort
        unordered_map<int, int> mp;
        int bucketSize = 0;
        for(auto& num: nums){
            mp[num]++;
            bucketSize = max(bucketSize, mp[num]);
        }
        
        vector<int> buckets[bucketSize+1];
        
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(auto& h: mp){
            mn = min(mn, h.second);
            mx = max(mx, h.second);
            buckets[h.second].push_back(h.first);
        }
        //cout<<mn<<" "<<mx<<endl;
        
        for(int i=mn;i<=mx;i++){
            sort(buckets[i].begin(), buckets[i].end());
        }
        
        vector<int> res;
        for(int i=mx;i>=mn;i--){
            for(int j=0;j<buckets[i].size();j++){
                k--;
                res.push_back(buckets[i][j]);
                if(k==0) return res;
            }
        }
        
        return res;
    }
};
