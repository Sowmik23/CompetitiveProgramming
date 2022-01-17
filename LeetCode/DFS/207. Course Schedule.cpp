class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        //mainly topological sorting
        // so first create graph 
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(int i=0;i<prerequisites.size();i++){
            int course = prerequisites[i][0];
            int pre_course = prerequisites[i][1];
            
            indegree[course]++;
            graph[pre_course].push_back(course);
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> res;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            res.push_back(top);
            
            for(auto& i: graph[top]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        
        if(res.size()==numCourses) return true;
        return false;
    }
};
