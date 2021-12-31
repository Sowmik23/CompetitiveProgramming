class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> res;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            int src = prerequisites[i][1];
            int dst = prerequisites[i][0];
            indegree[dst]++;
            adjList[src].push_back(dst);
        }
       // cout<<"something"<<endl;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int top = q.front();
                q.pop();
                res.push_back(top);
                
                for(auto& num: adjList[top]){
                    indegree[num]--;
                    if(indegree[num]==0) q.push(num);
                }
            }
        }
        if(res.size()==numCourses) return res;
        return {};
    }
};
