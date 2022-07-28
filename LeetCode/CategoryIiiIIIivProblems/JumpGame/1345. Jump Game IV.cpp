class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        if(n<=1) return 0;
        
        unordered_map<int, vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(0);
        visited[0] = true;
        
        int steps = 0;
        while(!q.empty()){
            for(int i=q.size();i>0;i--){
                int top = q.front();
                q.pop();
                
                if(top==n-1) return steps;
                vector<int> &next = mp[arr[top]];
                
                next.push_back(top-1);
                next.push_back(top+1);
                
                for(auto& i: next){
                    if(i>=0 and i<n and visited[i]==false){
                        visited[i] = true;
                        q.push(i);
                    }
                }
                next.clear();
            }
            steps++;
        }
        
        return 0;
    }
};
