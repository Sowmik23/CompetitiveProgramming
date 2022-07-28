class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        //if(prerequisites.size()==0) return {};
        
        vector<int> indegree(numCourses, 0), res;
        vector<vector<int>> graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int c = prerequisites[i][0];
            int preC = prerequisites[i][1];
            indegree[c]++;
            graph[preC].push_back(c);
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
       
        while(!q.empty()){
            int top = q.front();
            
            q.pop();
            res.push_back(top);
            for(auto& x: graph[top]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        
        if(res.size()==numCourses) return res;
        return {};
    }
};
