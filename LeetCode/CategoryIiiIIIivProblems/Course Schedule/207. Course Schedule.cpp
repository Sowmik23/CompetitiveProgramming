class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        if(numCourses>0 && prerequisites.size()==0) return true;
        
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            int course = prerequisites[i][0];
            int preCourse = prerequisites[i][1];
            
            graph[preCourse].push_back(course);
            indegree[course]++;
        }
        
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        set<int> st;
        while(!q.empty()){
            int top = q.front();
            st.insert(top);
            q.pop();
            for(auto& x: graph[top]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
    
        if(st.size()==numCourses) return true;
        return false;
    }
};
