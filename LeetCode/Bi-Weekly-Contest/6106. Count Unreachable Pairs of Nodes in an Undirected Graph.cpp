class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> res;
        vector<bool> visited(n, false);
        
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                int c = 0;
                c = dfs_visit(graph, i, visited, c);
                if(c==0) c++;
                res.push_back(c);
            }
        }
        
        //pre-process res;
        long long ans = 0;
        
        vector<int> suffixSum(res.size(), 0);
        // for(auto& i: res) cout<<i<<" ";
        // cout<<"res end"<<endl;
        
        suffixSum[res.size()-1] =res[res.size()-1];
        for(int i=res.size()-2;i>0;i--){
            suffixSum[i] +=res[i]+suffixSum[i+1];
        }
        // for(auto& s: suffixSum) cout<<s<<" "<<" ";
        // cout<<"ss"<<endl;
        
        for(int i=0;i<res.size()-1;i++) {
            ans += (long long) res[i]*suffixSum[i+1];
        }
        
        return ans;
    }
private:
    int dfs_visit(vector<vector<int>> &graph, int u, vector<bool>&visited, int &c){
        for(auto& x: graph[u]){
            
            if(visited[x]==false){
                c+=1;
                visited[x] = true;
                dfs_visit(graph, x, visited, c);
            }
        }
        
        return c;
    }
};
