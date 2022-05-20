class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n+1, -1);
        vector<bool> visited(n+1, false);
        queue<int> q;
        
        for(int j=0;j<n;j++){
            if(color[j]!=-1) continue;
            
            q.push(j);
            color[j] = 0;
            visited[j] = true;
            while(!q.empty()){
                int top = q.front();
                visited[top] = true;
                q.pop();
                int c = color[top];
                int x = (c==0 ? 1: 0);
                for(auto& i: graph[top]){
                    if(visited[i]==false){
                        if(color[i]==c) return false;
                        else {
                            color[i] = x;
                        }
                        q.push(i);   
                    }
                }
            }   
        }
        
        return true;
    }
};
