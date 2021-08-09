class Solution {
public:
    bool judgeCircle(string moves) {
        
        int updownlevel = 0;
        int leftrightlevel = 0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='R') leftrightlevel +=1;
            else if(moves[i]=='L') leftrightlevel -=1;
            else if(moves[i]=='U') updownlevel +=1;
            else if(moves[i]=='D') updownlevel -=1;
        }
        
        if(leftrightlevel==0 and updownlevel==0) return true;
        else return false;
    }
};
