// 1337. The K Weakest Rows in a Matrix
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        auto cmp = [](auto &a, auto &b){
            if(a.first==b.first) return a.second>=b.second;
            return a.first>b.first;
        };

        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            int j = 0;
            int cnt = 0;
            while(j<n and mat[i][j]==1){
                j++;
                cnt++;
            }
            pq.push({cnt, i});
        }
        while(!pq.empty() and k>0){
            auto top = pq.top();
            pq.pop();
            res.push_back(top.second);
            k--;
        }
        return res;
    }
};