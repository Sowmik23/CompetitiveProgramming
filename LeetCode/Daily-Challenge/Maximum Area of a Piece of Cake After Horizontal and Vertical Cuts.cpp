class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        
        int mx1, mx2;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        mx1 = horizontalCuts[0];
        for(int i=1;i<horizontalCuts.size();i++){

            mx1 = max(mx1, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        mx1 = max(mx1, abs(h-horizontalCuts[horizontalCuts.size()-1]));
        
        mx2=verticalCuts[0];
        for(int i=1;i<verticalCuts.size();i++){

           mx2 = max(mx2, verticalCuts[i]-verticalCuts[i-1]); 
        }
        mx2 = max(mx2, abs(w - verticalCuts[verticalCuts.size()-1]));
        
        
        return ((long long)(mx1%1000000007)*(long long)(mx2%1000000007))%1000000007;
    }
};
