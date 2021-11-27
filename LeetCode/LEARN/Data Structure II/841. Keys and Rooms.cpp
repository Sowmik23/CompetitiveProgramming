class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        vector<bool> visited(rooms.size(), false);
        
        stack<int> stk;
        stk.push(0);
       
        while(!stk.empty()){
            int r = stk.top();
            stk.pop();
            
            if(!visited[r]){
                for(int i=0;i<rooms[r].size();i++){
                    stk.push(rooms[r][i]);
                }    
            }
            visited[r] = true;
        }
        
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==false) return false;
        }
        
        return true;
    }
};
