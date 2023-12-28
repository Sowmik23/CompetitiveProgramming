// 2849. Determine if a Cell Is Reachable at a Given Time

// 2849. Determine if a Cell Is Reachable at a Given Time

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        //math
        int width = abs(sx-fx);
        int hight = abs(sy-fy);

        if(width==0 and hight==0 and t==1) return false;
        return t>=max(width, hight);
    }
};