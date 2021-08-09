class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        //just check if the rectangles intercept or not
        
        if( (max(rec1[0], rec2[0]) < min(rec1[2], rec2[2])) and (max(rec1[1], rec2[1]) < min(rec1[3], rec2[3])) )return true;
         return false;
    }
};
