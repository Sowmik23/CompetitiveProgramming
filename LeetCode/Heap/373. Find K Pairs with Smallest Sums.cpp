// 373. Find K Pairs with Smallest Sums
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> res;
        set<pair<int, int>> visited;

        pq.push({nums1[0]+nums2[0], {0, 0}});
        visited.insert({0, 0});

        while(k-- and !pq.empty()){
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            res.push_back({nums1[i], nums2[j]});
            
            if(i+1<m and visited.find({i+1, j})==visited.end()){
                pq.push({nums1[i+1]+nums2[j], {i+1, j}});
                visited.insert({i+1, j});
            }

            if(j+1<n and visited.find({i, j+1})==visited.end()){
                pq.push({nums1[i]+nums2[j+1], {i, j+1}});
                visited.insert({i, j+1});
            }
        }
        return res;
    }
};