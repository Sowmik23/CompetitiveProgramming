class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
     
        int n = graph.size();
        int ans = 0;
        
        queue<vector<int>> q;
        set<pair<int, int>> st;
        
        //starting bfs from every node and mask is used to check state of all visited node
        for(int i=0;i<n;i++){
            
            vector<int> v(3, 0);
            int mask = (1<<i);
            int node = i;
            int cost = 0;
            
            v[0] = cost;
            v[1] = node;
            v[2] = mask;
            
            q.push(v);
            st.insert({node, mask});
        }
        
        //start bfs
        while(q.size()>0){
            auto front = q.front();
            q.pop();
            
            //all bits are set which means all nodes are finally visited
            if(front[2]==(1<<n)-1){
                ans = front[0];
                break;
            }
            
            for(auto& x : graph[front[1]]){
                int mask = front[2] | (1<<x);
                
                //checking that this state is not visited yet
                if(st.find({x, mask})==st.end()){
                    st.insert({x, mask});
                    
                    vector<int> v(3, 0);
                    v[0] = front[0]+1;
                    v[1] = x;
                    v[2] = mask;
                    
                    q.push(v);
                }
            }
        }
        
        return ans;
    }
};
