class Solution {
public:
    unordered_map<int, vector<int>> mp;
    vector<int> color;
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        //BFS: Time(O(V+E))
        for(auto& dis : dislikes){
            mp[dis[0]].push_back(dis[1]);
            mp[dis[1]].push_back(dis[0]);
        }
        color = vector<int> (n+1, -1);

        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(!bfs(i)) return false;
            }
        }

        return true;
    }
private:
    bool bfs(int u){
        color[u]=1;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto t: mp[top]){
                if(color[t]==-1){
                    color[t] = 1-color[top];
                    q.push(t);
                }
                else if(color[t]==color[top]) return false;
            }
        }
        return true;
    }
};
