
auto speedup = []() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    return 0;
}();

class Solution {
    
public:
    //compare function to sort the mp according to greater frequency
     struct comp {
         bool operator() (pair<int, int> a, pair<int, int> b){
             return a.second>b.second;
         }
     };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //approach-01: map + heap: O(nlogk)
        
      /*  map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        //compare function to sort the mp according to greater frequency
        auto comp = [&mp](int num1, int num2){
            return mp[num1]>mp[num2];
        };
        
        //initialize pq with most frequent element at the top
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        
        
        for(auto i: mp){
            pq.push(i.first);
            if(pq.size()>k) pq.pop();
        }
        
        vector<int> res(k);
        for(int i=k-1;i>=0;i--){
            res[i] = pq.top();
            pq.pop();
        }
        
        return res;
        
        */
        
        //same thing but another way to write compare function
        map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        
        
        //declare a heap/priority_queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        
        for(auto i: mp){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        
        vector<int> res(k);
        for(int i=k-1;i>=0;i--){
            res[i] = pq.top().first;
            pq.pop();
        }
        
        return res;
        
    }
    
};
