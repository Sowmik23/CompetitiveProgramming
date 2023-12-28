// 1311. Get Watched Videos by Your Friends
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        
        int n = friends.size();
        vector<vector<int>> indegree(n), outdegree(n);
        for(int i=0;i<n;i++){
            auto frd_list = friends[i];
            for(auto& frd: frd_list){
                outdegree[i].push_back(frd);
                indegree[frd].push_back(i);
            }
        }

        vector<int> level_frd_list;
        if(level>=id){
            //bfs on outdegree
            level_frd_list = bfs(outdegree, id, level, n); 
        }
        else {
            //bfs on indegree
            level_frd_list = bfs(indegree, id, level, n); 
        }

        if(level_frd_list.empty()) level_frd_list.push_back(id);
        unordered_map<string, int> mp;
        for(auto &f: level_frd_list){
            for(auto& str: watchedVideos[f]){
                mp[str]++;
            }
        }

        auto cmp = [](const auto &a, const auto &b){
            if(a.first==b.first) return a.second>b.second;
            return a.first>b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        for(auto& m: mp){
            pq.push({m.second, m.first});
        }

        vector<string> res;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            // cout<<top.first<<" "<<top.second<<endl;
            res.push_back(top.second);
        }
        return res;
    }
private:
    vector<int> bfs(vector<vector<int>> &frd_list, int &id, int &level, int n){
        vector<int> res;
        vector<bool> visited(n, false);
        visited[id] = true;
        queue<int> q;
        for(auto &frd: frd_list[id]){
            q.push(frd);
            if(level==1){
                res.push_back(frd);
            } 
        }
        if(level==1) return res;
        int l = 1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                int top = q.front();
                q.pop();
                if(visited[top]) continue;
                visited[top] = true;
                if(l==level) {
                    res.push_back(top);
                    // cout<<l<<" "<<level<<" "<<top<<endl;
                }
                else {
                    for(auto &frd_frd: frd_list[top]){
                        q.push(frd_frd);
                    }
                }
            }
            l++;
        }
        return res;
    }
};