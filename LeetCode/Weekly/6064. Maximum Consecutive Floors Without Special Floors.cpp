class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(), special.end());
        int mx = 0;
        
        mx = max(mx, special[0]-bottom);
        mx = max(mx, top-special[special.size()-1]);
        
        for(int i=1;i<special.size();i++){
            mx = max(mx, special[i]-special[i-1]-1);
        }
        
        return mx;
    }
};
