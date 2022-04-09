class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        unordered_map<int, int> top, bottom, same;
        
        for(int i=0;i<tops.size();i++){
            top[tops[i]]++;
            bottom[bottoms[i]]++;
            if(tops[i]==bottoms[i]) same[tops[i]]++;
        }
        
        
        for(int i=1;i<=6;i++){
            if(top[i]+bottom[i]-same[i]==tops.size()){
                return min(top[i]-same[i], bottom[i]-same[i]);
            }
        }
        
        return -1;
    }
};
