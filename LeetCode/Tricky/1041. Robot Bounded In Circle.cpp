class Solution {
public:
    bool isRobotBounded(string instructions) {
     
        
        //initial 
        int x = 0, y = 0;
        int i = 0;
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(auto& ch: instructions){
            if(ch=='L'){
                i = (i+3)%4;
            }
            else if(ch=='R'){
                i = (i+1)%4;
            }
            else {
                x+= direction[i][0];
                y+= direction[i][1];
            }
        }
        
        return (x==0 and y==0) or i>0;
    }
};
